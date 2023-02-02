#include <iostream>
using namespace std;
int b = 0, w = 0;
int map[128][128];

void count(int x, int y, int N) {
    int wflag = 1, bflag = 1;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            if(map[x+i][y+j] == 1) wflag = 0;
            if(map[x+i][y+j] == 0) bflag = 0;
        }
    }

    if(wflag) {
        w++;
        return;
    }
    if(bflag) {
        b++;
        return;
    }

    count(x, y, N/2);
    count(x + N/2, y, N/2);
    count(x, y + N/2, N/2);
    count(x + N/2, y + N/2, N/2);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;

    cin >> N;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cin >> map[i][j];
        }
    }
    count(0, 0, N);
    cout << w << '\n' << b;

    return 0;
}