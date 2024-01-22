#include <iostream>
#include <vector>
using namespace std;

int n;
int dy[4] = {0, 0, 1, -1};
int dx[4] = {1, -1, 0, 0};
int dfs(int y, int x);
vector<vector<int> > tile, dp;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
    int ans = 0;
    // input & init
    cin >> n;
    tile = vector<vector<int> >(n, vector<int>(n, 0));
    dp = vector<vector<int> >(n, vector<int>(n, -1));
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> tile[i][j];
    // solve
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            ans = max(ans, dfs(i, j));
    cout << ans << '\n';

    return 0;
}

int dfs(int y, int x) {
    if(dp[y][x] != -1) return dp[y][x];
    int ny, nx;
    int &ret = dp[y][x];

    ret = 1;
    for(int i = 0; i < 4; i++) {
        ny = y + dy[i];
        nx = x + dx[i];
        if(ny < 0 || nx < 0 || ny >= n || nx >= n) continue;
        if(tile[ny][nx] <= tile[y][x]) continue;

        ret = max(ret, 1 + dfs(ny, nx));
    }

    return ret;
}