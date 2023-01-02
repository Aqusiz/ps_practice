#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int N, M;
int map[2][100][100];
queue< pair<int, int> > q;

int is_available(int i, int j) {
    if(i < 0) return 0;
    if(j < 0) return 0;
    if(i > N-1) return 0;
    if(j > M-1) return 0;
    if(map[0][i][j] == 0) return 0;
    if(map[1][i][j] != 0) return 0;

    return 1;
}

void go_to(int i, int j, int path) {
    q.push(make_pair(i, j));
    map[1][i][j] = path;
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> M;
    char temp;
    int a, b, path;

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            cin >> temp;
            map[0][i][j] = (int)(temp - '0');
            map[1][i][j] = 0;
        }
    }
    q.push(make_pair(0, 0));
    map[1][0][0] = 1;
    while(!q.empty()) {
        a = q.front().first;
        b = q.front().second;
        path = map[1][a][b];
        q.pop();

        if(is_available(a - 1, b)) go_to(a - 1, b, path + 1);
        if(is_available(a, b - 1)) go_to(a, b - 1, path + 1);
        if(is_available(a + 1, b)) go_to(a + 1, b, path + 1);
        if(is_available(a, b + 1)) go_to(a, b + 1, path + 1);
    }
    cout << map[1][N-1][M-1] << '\n';

    return 0;
}