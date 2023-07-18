#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int T, h, w, ans;
int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};
bool keys[30];
char map[101][101];
bool visited[101][101];
vector<pair<int, int> > start;

void init_case() {
    string k;
    // initialize
    ans = 0;
    for(int i = 0; i <= 'z' - 'a'; i++) {
        keys[i] = false;
    }
    start = vector<pair<int, int> >();
    // input map
    cin >> h >> w;
    for(int i = 0; i < h; i++) {
        for(int j = 0; j < w; j++) {
            cin >> map[i][j];
            // store possible start points
            if((i == 0 || j == 0 || i == h-1 || j == w-1) && map[i][j] != '*') {
                start.push_back(make_pair(i, j));
            }
        }
    }
    // input init keys
    cin >> k;
    if(k.compare("0") != 0) {
        for(int i = 0; i < k.size(); i++) {
            keys[k[i] - 'a'] = true;
        }
    }
}

void init_dfs() {
    // init visited info for new dfs
    for(int i = 0; i < h; i++) {
        for(int j = 0; j < w; j++) {
            visited[i][j] = false;
        }
    }
}

bool dfs(int a, int b) {
    if(map[a][b] == '*') return false;
    if(map[a][b] >= 'A' && map[a][b] <= 'Z' && !keys[map[a][b] - 'A']) return false;

    bool flag = false;
    visited[a][b] = true;
    // if find new key, have to do dfs from first again
    if(map[a][b] >= 'a' && map[a][b] <= 'z') {
        keys[map[a][b] - 'a'] = true;
        flag = true;
    }
    else if(map[a][b] == '$')
        ans++;
    map[a][b] = '.';

    for(int i = 0; i < 4; i++) {
        if(a + dx[i] < 0 || a + dx[i] > h - 1 || b + dy[i] < 0 || b + dy[i] > w - 1) continue;
        if(visited[a + dx[i]][b + dy[i]]) continue;

        flag = flag || dfs(a + dx[i], b + dy[i]);
    }

    return flag;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> T;
    for(int t = 0; t < T; t++) {
        // init
        init_case();
        
        // solve
        int a = 0, b = 0;
        bool flag = false;
        for(int i = 0; i < start.size(); i++) {
            a = start[i].first;
            b = start[i].second;
            init_dfs();
            flag = flag || dfs(a, b);
            // if found new key, then do dfs from first again
            if(flag) {
                flag = false;
                i = -1;
            }
        }
        cout << ans << '\n';
    }

    return 0;
}