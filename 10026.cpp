#include <iostream>
#include <queue>
using namespace std;
int N;
int ans[2] = {0, 0};
char map[2][101][101];
bool visited[101][101];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void bfs() {
    int x, y, nx, ny;
    char prev_map;
    queue<pair<pair<int, int>, char> > q;
    // try bfs twice
    for(int t = 0; t < 2; t++) {
        // init queue and visited array
        q = queue<pair<pair<int, int>, char> >();
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < N; j++) {
                visited[i][j] = false;
            }
        }
        // bfs from every not-visited point
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < N; j++) {
                if(visited[i][j]) continue;
                ans[t]++;

                q.push(make_pair(make_pair(i, j), map[t][i][j]));
                visited[i][j] = true;
                while(!q.empty()) {
                    y = q.front().first.first;
                    x = q.front().first.second;
                    prev_map = q.front().second;
                    q.pop();

                    for(int k = 0; k < 4; k++) {
                        ny = y + dy[k];
                        nx = x + dx[k];
                        if(nx < 0 || ny < 0 || nx > N-1 || ny > N-1) continue;
                        if(visited[ny][nx]) continue;
                        if(map[t][ny][nx] != prev_map) continue;

                        q.push(make_pair(make_pair(ny, nx), map[t][ny][nx]));
                        visited[ny][nx] = true;
                    }
                }
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cin >> map[0][i][j];
            map[1][i][j] = map[0][i][j];
            if(map[1][i][j] == 'G') map[1][i][j] = 'R';
        }
    }
    bfs();
    cout << ans[0] << " " << ans[1] << '\n';
    return 0;
}