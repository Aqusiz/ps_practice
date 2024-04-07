#include <iostream>
#include <vector>
using namespace std;

int n;
vector<int> dp[2];
vector<bool> visited;
vector<vector<int> > adj;

int dfs(int vertex, int is_include) {
    if(dp[is_include][vertex] != -1) return dp[is_include][vertex];
    int& included_value = dp[1][vertex];
    int& not_included_value = dp[0][vertex];
    
    visited[vertex] = true;
    included_value = 1;
    not_included_value = 0;
    for(auto& v: adj[vertex]) {
        if(visited[v]) continue;
        included_value += min(dfs(v, 0), dfs(v, 1));
        not_included_value += dfs(v, 1);
    }

    return dp[is_include][vertex];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int u, v;

    cin >> n;
    adj = vector<vector<int> >(n + 1, vector<int>());
    dp[0] = vector<int>(n + 1, -1);
    dp[1] = vector<int>(n + 1, -1);
    visited = vector<bool>(n + 1, false);
    for(int i = 0; i < n - 1; i++) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    cout << min(dfs(1, 0), dfs(1, 1)) << '\n';

    return 0;
}