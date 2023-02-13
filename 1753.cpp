#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void dijkstra(int start, vector<pair<int, int> >* adj, int* d) {
    int cur_v, next_v, dist, w;
    priority_queue<pair<int, int> > pq; // pq = {(-w, v), ...};

    d[start] = 0;
    for(int i = 0; i < adj[start].size(); i++) {
        next_v = adj[start].at(i).first;
        dist = adj[start].at(i).second;
        if(d[next_v] < dist) continue;  // multiple edges between two vertices -> choose shortest one
        d[next_v] = dist;
        pq.push(make_pair(-dist, next_v));
    }

    while(!pq.empty()) {
        cur_v = pq.top().second;
        dist = -pq.top().first;     // dist from start node to cur_v
        pq.pop();
        for(int i = 0; i < adj[cur_v].size(); i++) {
            next_v = adj[cur_v].at(i).first;
            w = adj[cur_v].at(i).second;        // weight between cur_v & next_v
            if(d[next_v] > dist + w) {
                d[next_v] = dist + w;
                pq.push(make_pair(-d[next_v], next_v));
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int V, E, K, u, v, w;
    int d[20001];
    vector<pair<int, int> > adj[20001]; // adj[u] = {(v, w), ...}

    cin >> V >> E >> K;
    for(int i = 0; i < E; i++) {
        cin >> u >> v >> w;
        adj[u].push_back(make_pair(v, w));
    }
    for(int i = 1; i <= V; i++) d[i] = INT32_MAX;

    dijkstra(K, adj, d);

    for(int i = 1; i <= V; i++) {
        if(d[i] == INT32_MAX) cout << "INF\n";
        else cout << d[i] << '\n';
    }
    return 0;
}