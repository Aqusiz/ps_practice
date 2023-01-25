#include <iostream>
using namespace std;
int N, M, K;
int map[50][50];

int is_available(int i, int j) {
    if(i < 0) return 0;
    if(j < 0) return 0;
    if(i > N-1) return 0;
    if(j > M-1) return 0;
    
    return map[i][j];
}

void traverse(int i, int j) {
    map[i][j] = 0;
    if(is_available(i - 1, j)) traverse(i - 1, j);
    if(is_available(i, j - 1)) traverse(i, j - 1);
    if(is_available(i + 1, j)) traverse(i + 1, j);
    if(is_available(i, j + 1)) traverse(i, j + 1);

    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T, x, y, cnt;

    cin >> T;
    for(int t = 0; t < T; t++) {
        cin >> M >> N >> K;
        cnt = 0;
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < M; j++) {
                map[i][j] = 0;
            }
        }

        for(int i = 0; i < K; i++) {
            cin >> x >> y;
            map[y][x] = 1;
        }

        for(int i = 0; i < N; i++) {
            for(int j = 0; j < M; j++) {
                if(map[i][j] == 0) continue;
                traverse(i, j);
                cnt++;
            }
        }

        cout << cnt << '\n';
    }

    return 0;
}