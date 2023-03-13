#include <iostream>
using namespace std;
int r[501], c[501];
int dp[501][501];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N, min, m, n;
    // input
    cin >> N;
    for(int i = 0; i < N; i++) {
        cin >> r[i] >> c[i];
    }
    // dp
    for(int i = 1; i < N; i++) {
        dp[i][i-1] = r[i-1] * c[i-1] * c[i];
        for(int j = i-2; j >= 0; j--) {
            min = INT32_MAX;
            m = i - j;
            n = 1;
            while(m > 0) {
                if(dp[i-m][j] + dp[i][j+n] + r[j] * c[i] * c[i-m] < min)
                    min = dp[i-m][j] + dp[i][j+n] + r[j] * c[i] * c[i-m];
                m--; n++;
            }
            dp[i][j] = min;
        }
    }
    cout << dp[N-1][0] << '\n';
    return 0;
}