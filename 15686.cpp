#include <iostream>
#include <cstdlib>
using namespace std;
int N, M, chick_num = 0, ans = INT32_MAX;
int map[50][50];

int get_distance(int i1, int j1, int i2, int j2) {
    return abs(i1 - i2) + abs(j1 - j2);
}

int cal() {
    int ret = 0, dist, dist_min = INT32_MAX;

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            if(map[i][j] != 1) continue;
            dist_min = INT32_MAX;
            for(int m = 0; m < N; m++) {
                for(int n = 0; n < N; n++) {
                    if(map[m][n] != 2) continue;
                    dist = get_distance(i, j, m, n);
                    if(dist_min > dist) dist_min = dist;
                }
            }
            ret += dist_min;
        }
    }
    return ret;
}

void delete_chick(int a, int b, int m) {
    if(m == M) {
        int ret = cal();
        if(ans > ret) ans = ret;
        return;
    }

    for(int i = a; i < N; i++) {
        for(int j = 0; j < N; j++) {
            if(i == a && j <= b) continue;
            if(map[i][j] != 2) continue;
            map[i][j] = 0;
            delete_chick(i, j, m - 1);
            map[i][j] = 2;
        }
    }
}

void solve() {
    if(M == chick_num) {
        ans = cal();
        return;
    }

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            if(map[i][j] != 2) continue;
            map[i][j] = 0;
            delete_chick(i, j, chick_num - 1);
            map[i][j] = 2;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cin >> map[i][j];
            if(map[i][j] == 2) chick_num++;
        }
    }
    solve();
    cout << ans << '\n';
    return 0;
}