#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
// dfs for topological sort
void dfs(int v, vector<int> *adj, bool *visited, deque<int> &dq) {
    int len = adj[v].size();
    visited[v] = true;
    for(int i = 0; i < len; i++) {
        if(visited[adj[v].at(i)]) continue;
        dfs(adj[v].at(i), adj, visited, dq);
    }
    dq.push_front(v);
}
// do topological sort by dfs and return sorted deque
deque<int> topologicalSort(int N, vector<int> *adj) {
    deque<int> dq;
    bool *visited = new bool[N+1];
    for(int i = 1; i <= N; i++) visited[i] = false;
    
    for(int i = 1; i <= N; i++) {
        if(visited[i]) continue;
        dfs(i, adj, visited, dq);
    }
    delete[] visited;
    return dq;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T;
    int N, K, W, u, v;
    int d[1001], dp[1001];
    vector<int> adj[1001];          // adj[u] = {v1, ...}: "u" -> v
    vector<int> incomming[1001];    // incomming[v] = {u1, ...}: u -> "v"
    deque<int> sorted;

    cin >> T;
    for(int t = 0; t < T; t++) {
        // input and init
        cin >> N >> K;
        for(int i = 1; i <= N; i++) {
            cin >> d[i];
            dp[i] = d[i];
            adj[i] = vector<int>();
            incomming[i] = vector<int>();
        }
        for(int i = 0; i < K; i++) {
            cin >> u >> v;
            adj[u].push_back(v);
            incomming[v].push_back(u);
        }
        cin >> W;
        // topological sort
        sorted = topologicalSort(N, adj);
        // dp
        for(int i = 0; i < sorted.size(); i++) {
            // select vertex v as sorted order
            v = sorted.at(i);
            for(int j = 0; j < incomming[v].size(); j++) {
                // find edges: u -> v
                u = incomming[v].at(j);
                // select largest delay between all predecessors
                if(dp[u] + d[v] > dp[v]) dp[v] = dp[u] + d[v];
            }
        }
        cout << dp[W] << '\n';
    }
}