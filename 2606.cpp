#include <iostream>
#include <queue>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, v, p, q, ans = 0;;
    int is_infected[101] = {0,};
    int adj[101][101];
    queue<int> que;
    for(int i = 0; i < 101; i++) {
        for(int j = 0; j < 101; j++)
            adj[i][j] = 0;
    }

    cin >> n >> v;
    for(int i = 0; i < v; i++) {
        cin >> p >> q;
        // undirectional graph
        adj[p][q] = adj[q][p] = 1;
    }
    // bfs
    que.push(1);
    is_infected[1] = 1;
    while(!que.empty()) {
        p = que.front();
        que.pop();
        for(int i = 1; i <= n; i++) {
            if(adj[p][i] == 0) continue;
            if(is_infected[i]) continue;
            que.push(i);
            is_infected[i] = 1;
        }
    }
    // except 1
    for(int i = 2; i <= n; i++) {
        if(is_infected[i]) ans++;
    }
    cout << ans << endl;

    return 0;
}