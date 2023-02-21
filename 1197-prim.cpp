#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int V, E;

long long prim(vector<pair<int, int> > *adj) {
    priority_queue<pair<int, pair<int, int> > > heap;   //{(-w, (u, v)), ...}
    bool visited[10001] = {false,}; // set S of vertices in m.s.t.
    int u, v, w, x, cnt = 0;
    long long ret = 0;
    // start from node 1
    for(int i = 0; i < adj[1].size(); i++) {
        v = adj[1].at(i).first;
        w = adj[1].at(i).second;
        heap.push(make_pair(-w, make_pair(1, v)));
    }
    visited[1] = true;
    cnt++;

    while(cnt < V) {
        u = heap.top().second.first;    // node already in m.s.t.
        x = heap.top().second.second;   // new node to be added in m.s.t.
        w = -(heap.top().first);           // weight of (u-x)
        heap.pop();
        if(visited[x]) continue;

        cnt++;
        ret += w;
        visited[x] = true;
        for(int j = 0; j < adj[x].size(); j++) {
            v = adj[x].at(j).first;
            w = adj[x].at(j).second;
            // skip if v is already in  m.s.t.
            // to push cross edges(between S, V-S) only into heap
            if(visited[v]) continue;
            heap.push(make_pair(-w, make_pair(x, v)));
        }
    }
    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int u, v, w;
    vector<pair<int, int> > adj[10001];

    cin >> V >> E;
    for(int i = 0; i < E; i++) {
        cin >> u >> v >> w;
        adj[u].push_back(make_pair(v, w));
        adj[v].push_back(make_pair(u, w));
    }
    cout << prim(adj) << '\n';
    return 0;
}