// https://www.algospot.com/judge/problem/read/FENCE
#include <iostream>
#include <vector>
#include <stack>

using namespace std;
// my code with stack (linear time)
int fence_max(vector<int>& fences) {
    int n = fences.size() - 1, ans = 0, temp;
    int i = 0, j = n - 1;
    stack<int> s1, s2;
    vector<int> first_off_idx = vector<int>(n, n);          // 앞에서부터 비교했을 때, 가장 처음 높이가 낮아지는 idx
    vector<int> first_off_idx_back = vector<int>(n, -1);    // 뒤에서부터 비교했을 때, 가장 처음 높이가 낮아지는 idx
    // i = 0, 1, 2, ..., n-1
    // j = n-1, n-2, ..., 0
    for(; i < n; i++) {
        j = (n-1) - i;
        while(!s1.empty() && fences[s1.top()] > fences[i]) {
            first_off_idx[s1.top()] = i;
            s1.pop();
        }
        while(!s2.empty() && fences[s2.top()] > fences[j]) {
            first_off_idx_back[s2.top()] = j;
            s2.pop();
        }
        s1.push(i);
        s2.push(j);
    }

    for(int i = 0; i < n; i++) {
        // fence[i]의 높이 * (앞뒤로 이어지는 너비)
        temp = fences[i] * ((first_off_idx[i] - i) + (i - first_off_idx_back[i]) - 1);
        ans = max(ans, temp);
    }

    return ans;
}
// code in the book with devide & conquer
// 문제를 3부분으로 쪼갠다. 1. 왼쪽 2. 오른쪽 3. 쪼개는 경계를 포함하는 양쪽
int devide_conquer(vector<int>& fences, int left, int right) {
    // base case: 1개의 울타리만 포함
    if(left == right) return fences[right];
    // 1, 2. 왼쪽 또는 오른쪽에 최대 넓이가 포함되는 경우
    int mid = (left + right) / 2;
    int ret = max(devide_conquer(fences, left, mid), devide_conquer(fences, mid + 1, right));
    // 3. 쪼개는 경계를 포함하는 양쪽
    int lo = mid, hi = mid + 1;
    int height = min(fences[lo], fences[hi]);
    ret = max(ret, height * 2);     // 양 옆 2칸부터 출발
    while(left < lo || hi < right) {
        // 항상 높이가 더 높은 쪽으로 한 칸 확장
        if(hi < right && (lo == left || fences[lo-1] < fences[hi+1])) {
            ++hi;
            height = min(height, fences[hi]);
        } else {
            --lo;
            height = min(height, fences[lo]);
        }
        // 확장된 넓이와 기존 넓이를 비교
        ret = max(ret, height * (hi - lo + 1));
    }
    return ret;
}

int main() {
    int C;
    int n;
    vector<int> fences;

    cin >> C;
    for(int c = 0; c < C; c++) {
        cin >> n;
        fences = vector<int>(n+1, 0);
        for(int i = 0; i < n; i++) {
            cin >> fences[i];
        }
        // cout << fence_max(fences) << '\n';
        cout << devide_conquer(fences, 0, n-1) << '\n';
    }
    return 0;
}