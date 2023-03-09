#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N, M, u, v, now, next, level, sum;
    int ans_v = 0, ans_len = INT32_MAX;
    bool visited[101];
    vector<int> adj[101];
    queue<pair<int, int> > q;

    cin >> N >> M;
    for(int i = 0; i < M ; i++) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(int i = 1; i <= N; i++) {
        // init
        sum = 0;
        for(int j = 1; j <= 100; j++) visited[j] = false;
        q = queue<pair<int, int> >();
        // bfs
        q.push(make_pair(i, 0));
        visited[i] = true;
        while(!q.empty()) {
            now = q.front().first;
            level = q.front().second;
            sum += level;
            q.pop();

            for(int j = 0; j < adj[now].size(); j++) {
                next = adj[now].at(j);
                if(visited[next]) continue;
                q.push(make_pair(next, level+1));
                visited[next] = true;
            }
        }
        // check answer
        if(sum < ans_len) {
            ans_len = sum;
            ans_v = i;
        }
    }
    cout << ans_v << '\n';
    return 0;
}