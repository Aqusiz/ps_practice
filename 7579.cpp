#include <iostream>
#include <vector>
using namespace std;
#define MAX_MEM 10000000

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N, M, ret = INT32_MAX;
    vector<int> m, c;
    vector<vector<int> > dp;

    cin >> N >> M;
    m = vector<int>(N, 0);
    c = vector<int>(N, 0);
    dp = vector<vector<int> >(N, vector<int>(101*N+1, 0));
    for(int i = 0; i < N; i++) cin >> m[i];
    for(int i = 0; i < N; i++) cin >> c[i];
    
    for(int i = 0; i < N; i++) {
        dp[i][c[i]] = m[i];
        if(m[i] >= M) ret = min(ret, c[i]);
    }
    // i means i-th app
    for(int i = 1; i < N; i++) {
        // j means the cost of i-th app
        for(int j = 0; j < 101*N+1; j++) {
            // i번째 app을 사용하지 못하는 경우의 메모리 양 (즉, j < the cost of i-th app)
            if(j < c[i]) dp[i][j] = dp[i-1][j];
            // i번째 app을 사용할 수 있는 경우의 메모리 양 (j >= the cost of i-th app)
            else dp[i][j] = max(dp[i-1][j-c[i]] + m[i], dp[i-1][j]);

            if(dp[i][j] >= M) ret = min(ret, j);
        }
    }
    cout << ret << '\n';

    return 0;
}