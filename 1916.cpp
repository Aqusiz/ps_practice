#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int INF = 1000000001;
int n, m;
vector<pair<int, int> > adj[1001];  // adj[a] = {(b, w), ...}
long long int dist[1001];

int dijk(int start, int dest) {
    priority_queue<pair<int, pair<int, int> > > pq; // pq = {(-w, (a, b)), ...}
    int a, b;
    long long int w;
    // init
    for(int i = 1; i <= n; i++) {
        dist[i] = INF;
    }
    dist[start] = 0;
    for(int i = 0; i < adj[start].size(); i++) {
        b = adj[start][i].first;
        w = adj[start][i].second;
        pq.push(make_pair(-w, make_pair(start, b)));
    }

    while(!pq.empty()) {
        a = pq.top().second.first;
        b = pq.top().second.second;
        w = -pq.top().first;
        pq.pop();

        if(dist[b] <= dist[a] + w) continue;
        
        for(int i = 0; i < adj[b].size(); i++) {
            pq.push(make_pair(-adj[b][i].second, make_pair(b, adj[b][i].first)));
        }
        dist[b] = dist[a] + w;
    }

    return dist[dest];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int a, b, w;

    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        cin >> a >> b >> w;
        adj[a].push_back(make_pair(b, w));
    }
    cin >> a >> b;

    cout << dijk(a, b) << '\n';
    return 0;
}