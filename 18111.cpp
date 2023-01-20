#include <iostream>
#include <limits.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N, M, B;
    int min_h = 257, max_h = 0, t = 0, b = 0, ans_h = 0, ans_t = INT_MAX;
    int map[501][501];
    // input
    cin >> N >> M >> B;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            cin >> map[i][j];
            if(map[i][j] < min_h) min_h = map[i][j];
            if(map[i][j] > max_h) max_h = map[i][j];
        }
    }
    // brute-force for every height from min_h to max_h
    for(int h = min_h; h <= max_h; h++) {
        t = 0; b = B;
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < M; j++) {
                // 1. remove block in 2 sec per block and add to inventory
                if(map[i][j] > h) {
                    t += (map[i][j] - h) * 2;
                    b += (map[i][j] - h);
                }
                // 2. put block in 1 sec per block from inventory
                else if(map[i][j] < h) {
                    t += (h - map[i][j]);
                    b -= (h - map[i][j]);
                }
            }
        }
        if(b < 0) continue; // not enough blocks
        if(t <= ans_t) {
            ans_h = h;
            ans_t = t;
        }
    }

    cout << ans_t << " " << ans_h << endl;

    return 0;
}