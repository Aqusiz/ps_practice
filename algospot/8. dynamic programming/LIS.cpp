#include <iostream>
#include <vector>

using namespace std;

int n;
int arr[501], dp[501];
// my code w/o recursion
int LIS() {
    int ret = 0;
    for(int i = 1; i < n; i++) {
        int max_len = 0;
        for(int j = 0; j < i; j++) {
            if(arr[i] > arr[j]) max_len = max(max_len, dp[j]);
        }
        dp[i] = max_len + 1;
        ret = max(ret, dp[i]);
    }

    return ret;
}
// book code: 완전 탐색
// lis(A): 수열 A를 받아, 그 중 가장 긴 LIS의 길이를 반환.
int lis(const vector<int>& A) {
    if(A.empty()) return 0;

    int ret = 0;
    for(int i = 0; i < A.size(); i++) {
        vector<int> B;
        // B: A[i]보다 큰 수들만 넣은 부분 수열
        for(int j = i+1; j < A.size(); j++) {
            if(A[j] > A[i])
                B.push_back(A[j]);
        }
        ret = max(ret, lis(B) + 1);
    }
    return ret;
}
// book code 2: 메모이제이션 적용
// lis(A)는 배열을 입력으로 받기 때문에 메모이제이션이 까다롭다 -> 입력 단순화
// 입력 A는 반드시 다음 둘 중 하나이다 1. 원래 주어진 수열 S  2. 원소 S[i]에 대해, idx가 i보다 크고 값이 S[i]보다 큰 원소들만 모아 둔 부분 수열
// 이때 2번 정의에 해당하는 입력들은 전부 idx와 1:1 대응
// lis2(start): S[start]에서 시작하는 부분 증가 수열 중 최대의 길이
int lis2(int start) {
    int& ret = dp[start];
    if(ret != 0) return ret;

    ret = 1;
    for(int next = start+1; next < n; next++) {
        if(arr[next] > arr[start])
            ret = max(ret, lis2(next) + 1);
    }
    return ret;
}
int main() {
    int C;
    cin >> C;
    for(int c = 0; c < C; c++) {
        cin >> n;
        for(int i = 0; i < n; i++) {
            cin >> arr[i];
            dp[i] = 1;
        }
        cout << LIS() << '\n';
    }
    return 0;
}