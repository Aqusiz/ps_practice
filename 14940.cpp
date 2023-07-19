#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int map[1001][1001];
bool visited[1001][1001];
int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m;
    int x, y, path;
    queue<pair<pair<int, int>, int> > q;

    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> map[i][j];
            visited[i][j] = false;

            if(map[i][j] == 2) {
                x = i;
                y = j;
                map[i][j] = 0;
            }
        }
    }

    q.push(make_pair(make_pair(x, y), 0));
    visited[x][y] = true;
    while(!q.empty()) {
        x = q.front().first.first;
        y = q.front().first.second;
        path = q.front().second;
        q.pop();
        map[x][y] = path + map[x][y];

        for(int i = 0; i < 4; i++) {
            if(x + dx[i] < 0 || y + dy[i] < 0 || x + dx[i] > n-1 || y + dy[i] > m-1) continue;
            if(map[x + dx[i]][y + dy[i]] == 0) continue;
            if(visited[x + dx[i]][y + dy[i]]) continue;

            q.push(make_pair(make_pair(x + dx[i], y + dy[i]), map[x][y]));
            visited[x + dx[i]][y + dy[i]] = true;
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(visited[i][j]) cout << map[i][j] << ' ';
            else if(map[i][j] == 0) cout << 0 << ' ';
            else cout << -1 << ' ';
        }
        cout << '\n';
    }
    return 0;
}