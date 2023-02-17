#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int V;
int dist[100001];
vector<pair<int, int> > adj[100001];    // adj[u] = {(v, w), ... }

int find_dist_node(int root) {
    int prev, curr, next, w, max_node, max_len = 0;
    queue<pair<int, int> > q;   // {(curr, prev), ... }

    for(int i = 1; i <= V; i++) dist[i] = INT32_MAX;
    
    q.push(make_pair(root, 0));
    dist[root] = 0;
    while(!q.empty()) {
        curr = q.front().first;
        prev = q.front().second;
        q.pop();

        for(int i = 0; i < adj[curr].size(); i++) {
            next = adj[curr].at(i).first;
            w = adj[curr].at(i).second;
            if(next == prev) continue;
            if(dist[next] != INT32_MAX) continue;
            
            q.push(make_pair(next, curr));
            dist[next] = dist[curr] + w;
            if(dist[next] > max_len) {
                max_node = next;
                max_len = dist[next];
            }
        }
    }
    return max_node;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int u, v, w;

    cin >> V;
    for(int i = 0; i < V; i++) {
        cin >> u;
        while(true) {
            cin >> v;
            if(v == -1) break;
            cin >> w;
            adj[u].push_back(make_pair(v, w));
            adj[v].push_back(make_pair(u, w));
        }
    }

    u = find_dist_node(1);
    v = find_dist_node(u);
    cout << dist[v] << '\n';
    return 0;
}