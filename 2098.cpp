#include <iostream>
#include <vector>
using namespace std;

#define INF 987654321
int N;
int w[16][16];
int dp[16][1 << 16];
int ans = INF;
int done = 0;

int go(int n, int mask) {
    if(mask == done) return (w[n][0] == 0) ? INF : w[n][0];
    if(dp[n][mask] != -1) return dp[n][mask];

    int new_mask;
    dp[n][mask] = INF;
    for(int i = 0; i < N; i++) {
        if(mask & (1 << i)) continue;
        if(w[n][i] == 0) continue;

        new_mask = mask | (1 << i);
        dp[n][mask] = min(dp[n][mask], w[n][i] + go(i, new_mask));
    }

    return dp[n][mask];
}

int main() {
    cin >> N;
    done = (1 << N) - 1;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < (1 << N); j++) dp[i][j] = -1;
        for(int j = 0; j < N; j++) {
            cin >> w[i][j];
        }
    }
    ans = go(0, 1);
    cout << ans << '\n';
    return 0;
}