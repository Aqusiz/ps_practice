#include <iostream>
#include <vector>
using namespace std;

int n;
vector<int> dp[2];
vector<bool> visited;
vector<vector<int> > adj;

void dfs(int vertex) {
    visited[vertex] = true;
    dp[1][vertex] = 1;

    for(auto& child: adj[vertex]) {
        if(visited[child]) continue;
        dfs(child);
        dp[0][vertex] += dp[1][child];
        dp[1][vertex] += min(dp[1][child], dp[0][child]);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int u, v;

    cin >> n;
    adj = vector<vector<int> >(n + 1, vector<int>());
    dp[0] = vector<int>(n + 1, 0);
    dp[1] = vector<int>(n + 1, 0);
    visited = vector<bool>(n + 1, false);
    for(int i = 0; i < n - 1; i++) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1);
    cout << min(dp[0][1], dp[1][1]) << '\n';

    return 0;
}