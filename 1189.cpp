#include <iostream>
using namespace std;
int R, C, K, ans = 0;
char map[2][5][5];

int is_available(int i, int j) {
    if(map[0][i][j] == 'T') return 0;
    if(map[1][i][j] == 'O') return 0;
    if(i < 0) return 0;
    if(j < 0) return 0;
    if(i >= C) return 0;
    if(j >= R) return 0;

    return 1;
}

void go_to(int i, int j, int path){
    if(i == C-1 && j == 0 && path == K) {
        ans++;
        return;
    }
    map[1][i][j] = 'O';
    if(is_available(i - 1, j)) go_to(i - 1, j, path + 1);
    if(is_available(i, j - 1)) go_to(i, j - 1, path + 1);
    if(is_available(i + 1, j)) go_to(i + 1, j, path + 1);
    if(is_available(i, j + 1)) go_to(i, j + 1, path + 1);
    map[1][i][j] = 'X';
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> R >> C >> K;
    for(int i = 0; i < R; i++) {
        for(int j = 0; j < C; j++) {
            cin >> map[0][i][j];
            map[1][i][j] = 'X';
        }
    }
    go_to(0, R-1, 1);
    cout << ans << '\n';

    return 0;
}