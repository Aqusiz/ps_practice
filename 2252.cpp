#include <iostream>
#include <vector>
using namespace std;
int N, M;
bool visited[32001];
vector<int> sorted;
vector<int> adj[32001];

void dfs(int v) {
    visited[v] = true;
    for(int i = 0; i < adj[v].size(); i++) {
        if(visited[adj[v].at(i)]) continue;
        dfs(adj[v].at(i));
    }
    sorted.push_back(v);
}

void topologicalSort() {
    for(int i = 1; i <= N; i++) {
        if(visited[i]) continue;
        dfs(i);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int u, v;

    cin >> N >> M;
    for(int i = 0; i < M; i++) {
        cin >> u >> v;
        adj[u].push_back(v);
    }
    topologicalSort();
    // reverse
    for(int i = N-1; i >= 0; i--) {
        cout << sorted[i] << " ";
    }
    return 0;
}