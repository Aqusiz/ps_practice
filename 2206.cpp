#include <iostream>
#include <queue>
using namespace std;
int N, M;
int map[1001][1001];
// visited[i][j][0]: 벽을 부순 적 없는 경로, visited[i][j][1]: 벽을 부순 적 있는 경로
int visited[1001][1001][2];
int di[4] = {1, -1, 0, 0};
int dj[4] = {0, 0, 1, -1};

int bfs() {
    int i, j, ni, nj, is_removed;
    queue<pair<pair<int, int>, int> > q;
    q.push(make_pair(make_pair(0, 0), 0));
    visited[0][0][0] = 1;

    while(!q.empty()) {
        i = q.front().first.first;
        j = q.front().first.second;
        is_removed = q.front().second;
        q.pop();
        // 가장 먼저 경로 도달: 값 반환
        if(i == N-1 && j == M-1) return visited[i][j][is_removed];

        for(int k = 0; k < 4; k++) {
            ni = i + di[k]; nj = j + dj[k];
            // 맵 밖을 나가면 무시
            if(ni < 0 || nj < 0 || ni > N-1 || nj > M-1) continue;
            // 어떤 경로로든 여태껏 방문한 적 있다면 무시
            if(visited[ni][nj][is_removed]) continue;
            // 지금까지 벽을 부순 적 없고, 벽을 만났을 때: is_removed를 0에서 1로 바꾼다 
            if(map[ni][nj] == 1 && is_removed == 0) {
                q.push(make_pair(make_pair(ni, nj), 1));
                visited[ni][nj][1] = visited[i][j][0] + 1;
            }
            // 길을 만났을 때: 지금까지의 is_removed 상태를 그대로 넘겨준다.
            if(map[ni][nj] == 0) {
                q.push(make_pair(make_pair(ni, nj), is_removed));
                visited[ni][nj][is_removed] = visited[i][j][is_removed] + 1;
            }
        }
    }
    return -1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    char x;

    cin >> N >> M;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            cin >> x;
            map[i][j] = (int)(x - '0');
        }
    }
    cout << bfs() << '\n';
    return 0;
}