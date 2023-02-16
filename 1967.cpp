#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int n;
int dist[10001];
vector<pair<int, int> > adj[10001]; // adj[u] = {(v, w), ...}

// find the most distant node from root by bfs
// and save the length in dist[i]
int find_distant_node(int root) {
    int curr, prev, next, w, max_len = 0, max_node = root;
    queue<pair<int, int> > q;   // {(curr_node, prev_node), ...}

    for(int i = 1; i <= n; i++) dist[i] = INT32_MAX;

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

            q.push(make_pair(next, curr));
            dist[next] = dist[curr] + w;
            if(dist[next] > max_len) {
                max_len = dist[next];
                max_node = next;
            }
        }
    }
    return max_node;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int u, v, w, max = 0;
    
    cin >> n;
    for(int i = 0; i < n-1; i++) {
        cin >> u >> v >> w;
        adj[u].push_back(make_pair(v, w));
        adj[v].push_back(make_pair(u, w));
    }
    // find the most distant node from root 1
    u = find_distant_node(1);
    // find the most distant node from node u
    v = find_distant_node(u);

    cout << dist[v] << '\n';
    return 0;
}