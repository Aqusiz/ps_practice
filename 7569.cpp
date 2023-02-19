#include <iostream>
#include <queue>
using namespace std;
int N, M, H, ans;
int map[100][100][100];
int dx[6] = {1, -1, 0, 0, 0, 0};
int dy[6] = {0, 0, 1, -1, 0, 0};
int dz[6] = {0, 0, 0, 0, 1, -1};

void bfs() {
    int x, y, z, nx, ny, nz;
    queue<pair<pair<int, int>, int> > q;
    for(int k = 0; k < H; k++) {
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < M; j++) {
                if(map[k][i][j] != 1) continue;
                q.push(make_pair(make_pair(i, j), k));
            }
        }
    }
    ans = 1;    // default for 0 day
    while(!q.empty()) {
        y = q.front().first.first;
        x = q.front().first.second;
        z = q.front().second;
        q.pop();

        for(int i = 0; i < 6; i++) {
            ny = y + dy[i];
            nx = x + dx[i];
            nz = z + dz[i];
            if(nx < 0 || ny < 0 || nz < 0 || nx > M-1 || ny > N-1 || nz > H-1) continue;
            if(map[nz][ny][nx] != 0) continue;
            q.push(make_pair(make_pair(ny, nx), nz));
            map[nz][ny][nx] = map[z][y][x] + 1;
            if(map[nz][ny][nx] > ans) ans = map[nz][ny][nx];
        }
    }

    for(int k = 0; k < H; k++) {
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < M; j++) {
                if(map[k][i][j] == 0) {
                    ans = -1;
                    return;
                }
            }
        }
    }
    ans--;
}

int main() {
    ios:: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> M >> N >> H;
    for(int k = 0; k < H; k++) {
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < M; j++) {
                cin >> map[k][i][j];           
            }
        }
    }
    bfs();
    cout << ans << '\n';
    return 0;
}