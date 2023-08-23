#include <iostream>
#include <vector>

using namespace std;

int n, m, ans = 0;
int tile[51][51];
// 북, 동, 남, 서
int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};

bool is_front_0(int r, int c, int d) {
    int nr = r + dr[d], nc = c + dc[d];

    if(tile[nr][nc] == 0) return true;
    else return false;
}

bool is_near_0(int r, int c) {
    for(int d = 0; d < 4; d++) {
        if(is_front_0(r, c, d)) return true;
    }
    return false;
}

void go(int r, int c, int d) {
    // 1. 현재 칸 청소
    if(tile[r][c] == 0) {
        ans++;
        tile[r][c] = -1;
    }

    int nr, nc, nd;
    // 2. 주변 4칸 중 빈칸이 없는 경우
    if(!is_near_0(r, c)) {
        // 후진 방향
        nd = (d + 2) % 4;
        nr = r + dr[nd];
        nc = c + dc[nd];
        
        // 뒤쪽 칸이 벽이면, 멈춤
        if(tile[nr][nc] == 1) return;
        // 벽이 아니면, 방향을 유지한 채 후진
        else go(nr, nc, d);
    }
    // 3. 주변 4칸 중 빈칸이 있는 경우
    else {
        // 반시계 회전
        nd = (d + 3) % 4;
        // 바라보는 방향이 빈 칸일때까지 회전
        while(!is_front_0(r, c, nd)) {
            nd = (nd + 3) % 4;
        }
        // 전진
        go(r + dr[nd], c + dc[nd], nd);
    }
}

int main() {
    int r, c, d;

    cin >> n >> m;
    cin >> r >> c >> d;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> tile[i][j];
        }
    }

    go(r, c, d);

    cout << ans << '\n';
    return 0;
}