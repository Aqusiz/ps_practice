#include <iostream>
#include <vector>

using namespace std;

int n;
int triangle[100][100], dp[100][100];

int path(int y, int x) {
    if(y == n-1) return triangle[y][x];

    int& ret = dp[y][x];
    if(ret != 0) return ret;

    return ret = triangle[y][x] + max(path(y+1, x), path(y+1, x+1));
}

int main() {
    int C, input;
    cin >> C;
    for(int c = 0; c < C; c++) {
        cin >> n;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < i+1; j++) {
                cin >> triangle[i][j];
                dp[i][j] = 0;
            }
        }
        cout << path(0, 0) << '\n';
    }
    return 0;
}