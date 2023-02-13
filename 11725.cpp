#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void find_parent(vector<int>* graph, int* parent) {
    int p, c;
    queue<pair<int, int> > q;   // q = {(parent, child), ...}
    for(int i = 0; i < graph[1].size(); i++) {
        q.push(make_pair(1, graph[1].at(i)));
    }
    // bfs
    while(!q.empty()) {
        p = q.front().first;
        c = q.front().second;
        q.pop();

        if(c == 1 || parent[c] != 0) continue;      // skip visited node(or root)
        parent[c] = p;
        for(int i = 0; i < graph[c].size(); i++) {
            q.push(make_pair(c, graph[c].at(i)));
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N, u, v;
    int parent[100001] = {0,};
    vector<int>* adj;

    cin >> N;
    adj = new vector<int>[N+1];
    for(int i = 0; i < N-1; i++) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    find_parent(adj, parent);

    for(int i = 2; i <= N; i++) {
        cout << parent[i] << '\n';
    }
    return 0;
}