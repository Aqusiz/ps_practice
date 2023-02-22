#include <iostream>
using namespace std;
int N, M, ans = 0;
int map[500][500];
bool visited[500][500];
int dy[4] = {1, -1, 0, 0};
int dx[4] = {0, 0, 1, -1};

bool is_in(int i, int j) {
    if(i < 0 || j < 0 || i > N-1 || j > M-1) return false;
    return true;
}

void find_max(int y, int x, int sum, int depth) {
    int ny, nx;
    int x1, y1, x2, y2;
    if(depth == 4) {
        if(sum > ans) ans = sum;
        return;
    }
    // ㅏ ㅗ ㅓ ㅜ
    if(depth == 2) {
        for(int i = 2; i < 4; i++) {
            x1 = x + dx[i];
            for(int j = 0; j < 2; j++) {
                y2 = y + dy[j];
                if(!is_in(y2, x1)) continue;
                if(visited[y][x1] || visited[y2][x]) continue;
                if(sum + map[y][x1] + map[y2][x] > ans) ans = sum + map[y][x1] + map[y2][x];
            }
        }
    }
    
    for(int i = 0; i < 4; i++) {
        ny = y + dy[i];
        nx = x + dx[i];
        if(nx < 0 || ny < 0 || nx > M-1 || ny > N-1) continue;
        if(visited[ny][nx]) continue;

        visited[ny][nx] = true;
        find_max(ny, nx, sum+map[ny][nx], depth+1);
        visited[ny][nx] = false;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N >> M;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            cin >> map[i][j];
        }
    }

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            visited[i][j] = true;
            find_max(i, j, map[i][j], 1);
            visited[i][j] = false;
        }
    }
    cout << ans << '\n';
    return 0;
}