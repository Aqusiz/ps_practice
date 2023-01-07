#include <iostream>
using namespace std;
int N, ans = 1;
int map[2][100][100];   //if map[1][i][j] == 0, not available

int is_available(int i, int j) {
    if(i < 0) return 0;
    if(j < 0) return 0;
    if(i > N-1) return 0;
    if(j > N-1) return 0;
    
    return map[1][i][j];
}

void check_area(int i, int j) {
    map[1][i][j] = 0;

    if(is_available(i - 1, j)) check_area(i - 1, j);
    if(is_available(i, j - 1)) check_area(i, j - 1);
    if(is_available(i + 1, j)) check_area(i + 1, j);
    if(is_available(i, j + 1)) check_area(i, j + 1);
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int max = 0, cnt = 0;

    cin >> N;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cin >> map[0][i][j];
            map[1][i][j] = 0;
            if(map[0][i][j] > max) max = map[0][i][j];
        }
    }

    for(int level = 0; level <= max; level++) {
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < N; j++) {
                map[1][i][j] = (map[0][i][j] > level) ? 1 : 0;
            }
        }
        cnt = 0;
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < N; j++) {
                if(map[1][i][j] == 0) continue;
                cnt++;
                check_area(i, j);
            }
        }
        if(cnt > ans) ans = cnt;
    }

    cout << ans << endl;

    return 0;
}