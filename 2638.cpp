#include <iostream>
#include <vector>
using namespace std;

int n, m;
int dy[4] = {0, 0, 1, -1};
int dx[4] = {1, -1, 0, 0};
vector<vector<int> > tile;
bool dfs(int y, int x, vector<vector<bool> >& visited); // mark all air tiles as 2 and return true if there is no cheese
bool is_exposed(int y, int x);                          // check the tile is exposed to two or more air tiles

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
    int cnt, time = 0;
    vector<vector<bool> > visited;
    vector<vector<bool> > exposed;
    // input & init
    cin >> n >> m;
    tile = vector<vector<int> >(n, vector<int>(m, 0));
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m ;j++)
            cin >> tile[i][j];
    // solve
    for(;;time++) {
        visited = vector<vector<bool> >(n, vector<bool>(m, false));
        exposed = vector<vector<bool> >(n, vector<bool>(m, false));
        if(dfs(0, 0, visited)) {
            cout << time << '\n';
            break;
        };

        for(int i = 1; i < n - 1; i++) {
            for(int j = 1; j < m - 1; j++) {
                if(tile[i][j] != 1)
                    continue;
                exposed[i][j] = is_exposed(i, j);
            }
        }
        for(int i = 1; i < n - 1; i++) {
            for (int j = 1; j < m - 1; j++) {
                if(exposed[i][j])
                    tile[i][j] = 0;
            }
        }
    }

    return 0;
}

bool dfs(int y, int x, vector<vector<bool> >& visited) {
    /*
    mark all air tiles as 2 and return true if there is no cheese
    */
    bool ret = true;
    int ny, nx;

    tile[y][x] = 2;
    visited[y][x] = true;
    for(int i = 0; i < 4; i++) {
        ny = y + dy[i];
        nx = x + dx[i];
        if(ny < 0 || nx < 0 || ny >= n || nx >= m || visited[ny][nx]) continue;
        if(tile[ny][nx] == 1) {
            ret = false;
            continue;
        }
        ret = dfs(ny, nx, visited) && ret;
    }

    return ret;
}

bool is_exposed(int y, int x) {
    /*
    check the tile is exposed to two or more air tiles
    */
    int ny, nx, cnt = 0;

    for(int i = 0; i < 4; i++) {
        ny = y + dy[i];
        nx = x + dx[i];
        if(ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
        if(tile[ny][nx] == 2) cnt++;
    }
    
    return cnt >= 2;
}