#include <iostream>
#include <queue>
using namespace std;
int N, M;
int adj[1001][1001];
int visited[1001];

string dfs(int u);
string bfs(int u);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int V;
    int u, v;

    cin >> N >> M >> V;
    for(int i = 0; i < M; i++) {
        cin >> u >> v;
        adj[u][v] = 1;
        adj[v][u] = 1;
    }
    cout << dfs(V) << '\n';
    for(int i = 1; i <= N; i++) visited[i] = 0;
    cout << bfs(V) << '\n';

    return 0;
}

string dfs(int u) {
    string ans = to_string(u) + " ";
    visited[u] = 1;
    for(int i = 1; i <= N; i++) {
        if(adj[u][i] == 0) continue;
        if(visited[i]) continue;
        ans += dfs(i);
    }

    return ans;
}

string bfs(int u) {
    int v = u;
    queue<int> q;
    string ans;

    q.push(v);
    while(!q.empty()) {
        v = q.front();
        ans += (!visited[v]) ? to_string(v) + " " : "";
        visited[v] = 1;
        q.pop();

        for(int i = 1; i <= N; i++) {
            if(adj[v][i] == 0) continue;
            if(visited[i]) continue;
            q.push(i);
        }
    }

    return ans;
}