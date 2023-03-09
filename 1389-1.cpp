#include <iostream>
using namespace std;
#define INF 10000

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N, M;
    int u, v, ans_len = INT32_MAX, ans_v, sum = 0;
    int adj[101][101];
    // input & init
    cin >> N >> M;
    for(int i = 0; i <= N; i++) {
        for(int j = 0; j <= N; j++) {
            if(i == j) adj[i][j] = 0;
            else adj[i][j] = INF;
        }
    }
    for(int i = 0; i < M; i++) {
        cin >> u >> v;
        adj[u][v] = 1;
        adj[v][u] = 1;
    }
    // floyd-warshall
    for(int k = 1; k <= N; k++) {
        for(int i = 1; i <= N; i++) {
            for(int j = 1; j <= N; j++) {
                if(adj[i][j] > adj[i][k] + adj[k][j])
                    adj[i][j] = adj[i][k] + adj[k][j];
            }
        }
    }
    // find answer
    for(int i = 1; i <= N; i++) {
        sum = 0;
        for(int j = 1; j <= N; j++) {
            if(adj[i][j] == INF) continue;
            sum += adj[i][j];
        }
        if(sum < ans_len) {
            ans_len = sum;
            ans_v = i;
        }
    }
    cout << ans_v << '\n';
    return 0;
}