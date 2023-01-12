#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    int adj[100][100];
    cin >> N;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cin >> adj[i][j];
        }
    }

    for(int k = 0; k < N; k++) {
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < N; j++) {
                if(adj[i][j] || (adj[i][k] && adj[k][j])) adj[i][j] = 1;
            }
        }
    }

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N - 1; j++) {
            cout << adj[i][j] << " ";
        }
        cout << adj[i][N-1] << '\n';
    }

    return 0;
}