#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N, M, temp;
    int x1, x2, y1, y2;
    int psum[1025][1025];
    cin >> N >> M;
    for(int j = 0; j <= N; j++) psum[0][j] = 0;
    for(int i = 1; i <= N; i++) {
        psum[i][0] = 0;
        for(int j = 1; j <= N; j++) {
            cin >> temp;
            psum[i][j] = psum[i-1][j] + psum[i][j-1] - psum[i-1][j-1] + temp;
        }
    }
    for(int i = 0; i < M; i++) {
        cin >> x1 >> y1 >> x2 >> y2;
        cout << psum[x2][y2] - psum[x2][y1-1] - psum[x1-1][y2] + psum[x1-1][y1-1] << '\n';
    }

    return 0;
}