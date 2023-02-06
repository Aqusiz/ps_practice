#include <iostream>
#include <queue>
using namespace std;
int N, M;
int map[8][8], map2[8][8];  // map2: back-up of map

int is_available(int i, int j) {
    if(i < 0) return 0;
    if(j < 0) return 0;
    if(i > N-1) return 0;
    if(j > M-1) return 0;
    if(map[i][j] != 0) return 0;
    return 1;
}

int count() {
    int x, y, ret = 0;
    queue<pair<int, int> > q;
    // spread virus by bfs
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            if(map[i][j] != 2) continue;
            q.push(make_pair(i, j));
        }
    }
    while(!q.empty()) {
        x = q.front().first;
        y = q.front().second;
        map[x][y] = 2;
        q.pop();

        if(is_available(x-1, y)) q.push(make_pair(x-1, y));
        if(is_available(x, y-1)) q.push(make_pair(x, y-1));
        if(is_available(x+1, y)) q.push(make_pair(x+1, y));
        if(is_available(x, y+1)) q.push(make_pair(x, y+1));
    }
    // count safe area and reset map
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            if(map[i][j] == 0) ret++;
            map[i][j] = map2[i][j];
        }
    }

    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int ans = 0, temp;

    cin >> N >> M;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            cin >> map[i][j];
            map2[i][j] = map[i][j];
        }
    }
    // first wall
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            if(map[i][j] != 0) continue;
            // second wall
            for(int n = i; n < N; n++) {
                for(int m = 0; m < M; m++) {
                    if(n == i && m <= j) continue;
                    if(map[n][m] != 0) continue;
                    // third wall
                    for(int p = n; p < N; p++) {
                        for(int q = 0; q < M; q++) {
                            if(p == n && q <= m) continue;
                            if(map[p][q] != 0) continue;
                            // set walls
                            map[i][j] = 1;
                            map[n][m] = 1;
                            map[p][q] = 1;
                            // count safe area and reset map
                            temp = count();
                            if(temp > ans) ans = temp;
                        }
                    }
                }
            }
        }
    }
    cout << ans << '\n';

    return 0;
}