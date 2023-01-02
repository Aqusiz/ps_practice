#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    char temp;
    int N, M;
    int mat[2][50][50];
    cin >> N >> M;
    if(N < 3 || M < 3) {
        cout << -1 << '\n';
        return 0;
    }
    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < N; j++) {
            for(int k = 0; k < M; k++) {
                cin >> temp;
                mat[i][j][k] = (int)(temp - '0');
            }
        }
    }
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            if(mat[0][i][j] == mat[1][i][j]) mat[0][i][j] = 0;
            else mat[0][i][j] = 1;
        }
    }


    return 0;
}