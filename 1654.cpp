#include <iostream>
#include <limits.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int K, N, ans_len = 0, max_len = 0, cnt;
    long long left, mid, right;
    int len[10001];

    cin >> K >> N;
    for(int i = 0; i < K; i++) {
        cin >> len[i];
        if(len[i] > max_len) max_len = len[i];
    }

    left = 1; right = (long long)max_len;
    while(left <= right) {
        mid = (left + right) / 2;
        cnt = 0;
        for(int i = 0; i < K; i++) {
            cnt += len[i] / mid;
        }
        if(cnt >= N) {
            ans_len = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    cout << ans_len << endl;

    return 0;
}