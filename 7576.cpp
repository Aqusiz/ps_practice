#include <iostream>
#include <queue>
#include <utility>
using namespace std;
int M, N;
int map[1000][1000];

int is_available(int i, int j) {
    if(i < 0) return 0;
    if(j < 0) return 0;
    if(i > N-1) return 0;
    if(j > M-1) return 0;
    if(map[i][j] != 0) return 0;

    return 1; 
}

void go_to(int i, int j,int path, queue<pair<int, int> > &q) {
    map[i][j] = path + 1;
    q.push(make_pair(i, j));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    queue<pair<int, int> > q;
    int x, y, ans = 0;
    cin >> M >> N;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            cin >> map[i][j];
            if(map[i][j] == 1) {
                q.push(make_pair(i, j));
            }
        }
    }

    while(!q.empty()) {
        x = q.front().first;
        y = q.front().second;
        q.pop();

        if(is_available(x-1, y)) go_to(x-1, y, map[x][y], q);
        if(is_available(x, y-1)) go_to(x, y-1, map[x][y], q);
        if(is_available(x+1, y)) go_to(x+1, y, map[x][y], q);
        if(is_available(x, y+1)) go_to(x, y+1, map[x][y], q);
    }

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            if(map[i][j] == 0) {
                cout << -1 << endl;
                return 0;
            }
            if(ans < map[i][j]) ans = map[i][j];
        }
    }
    cout << ans-1 << endl;

    return 0;
}