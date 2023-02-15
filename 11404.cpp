#include <iostream>
using namespace std;
const int INF = 1000000000;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m, u, v, w;
    int adj[101][101] = {0,};

    cin >> n >> m;
    for(int i = 0; i <= n; i++) {
        for(int j = 0; j <=n; j++) {
            adj[i][j] = (i == j) ? 0 : INF;
        }
    }
    for(int i = 0; i < m; i++) {
        cin >> u >> v >> w;
        if(adj[u][v] > w) adj[u][v] = w;
    }

    for(int k = 1; k <= n; k++) {
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                if(adj[i][j] > adj[i][k] + adj[k][j])
                    adj[i][j] = adj[i][k] + adj[k][j];
            }
        }
    }

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(adj[i][j] == INF) cout << "0 ";
            else cout << adj[i][j] << " ";
        }
        cout << '\n';
    }
    return 0;
}