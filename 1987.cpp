#include <iostream>
using namespace std;
int R, C, ans = 1;
char map[20][20];
bool ch_used[26];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void find_max_path(int y, int x, int length) {
    int ny, nx, new_len = length + 1;
    // update answer when the longer path is found
    if(new_len > ans) ans = new_len;

    for(int i = 0; i < 4; i++) {
        ny = y + dy[i];
        nx = x + dx[i];
        if(nx < 0 || ny < 0 || nx > C-1 || ny > R-1) continue;
        if(ch_used[map[ny][nx] - 'A']) continue;
        // backtracking
        ch_used[map[ny][nx] - 'A'] = true;
        find_max_path(ny, nx, new_len);
        ch_used[map[ny][nx] - 'A'] = false;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> R >> C;
    for(int i = 0; i < R; i++) {
        for(int j = 0; j < C; j++) {
            cin >> map[i][j];
        }
    }
    ch_used[map[0][0] - 'A'] = true;
    find_max_path(0, 0, 0);
    cout << ans << '\n';
    return 0;
}