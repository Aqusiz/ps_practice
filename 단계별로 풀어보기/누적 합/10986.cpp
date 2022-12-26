#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N, M, temp;
    long long ans = 0;
    int *psum, *remainder_cnt;
    cin >> N >> M;
    psum = (int *)malloc(sizeof(int) * N);
    remainder_cnt = (int *)malloc(sizeof(int) * M);
    // init
    for(int i = 0; i < M; i++) remainder_cnt[i] = 0;
    // prefix_sum array
    cin >> temp;
    psum[0] = temp % M;
    for(int i = 1; i < N; i++) {
        cin >> temp;
        psum[i] = (psum[i-1] + temp%M)%M;
    }
    // (psum[i] - psum[j-1])%M = 0
    // sum of empty array = 0
    remainder_cnt[0] = 1;
    for(int i = 0; i < N; i++) {
        // add the previous number of remainder
        ans += remainder_cnt[psum[i]];
        // add count 1
        remainder_cnt[psum[i]]++;
    }
    cout << ans << '\n';
}