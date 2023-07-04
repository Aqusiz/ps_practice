#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int N, M;
string board[10];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};

int main() {
    queue<pair<pair<pair<int, int>, pair<int, int> >, pair<int, int> > > q;
    int rx, ry, bx, by, ox, oy, count = 0;
    int n_rx, n_ry, n_bx, n_by;
    int r_move, b_move;
    int prev_d;
    pair<int, int> red, blue;
    
    // input and init
    cin >> N >> M;
    for(int i = 0; i < N; i++) {
        cin >> board[i];
    }
    for(int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if(board[i][j] == 'R') {
                rx = i; ry = j;
            } else if (board[i][j] == 'B') {
                bx = i; by = j;
            } else if (board[i][j] == 'O') {
                ox = i; oy = j;
            }
        }
    }

    // bfs
    q.push(make_pair(make_pair(make_pair(rx, ry), make_pair(bx, by)), make_pair(0, -1)));
    while(!q.empty()) {
        red = q.front().first.first;
        rx = red.first; ry = red.second;
        blue = q.front().first.second;
        bx = blue.first; by = blue.second;
        count = q.front().second.first;
        prev_d = q.front().second.second;
        q.pop();

        if(count == 10) break;

        count++;
        bool red_in = false, blue_in = false;
        for(int d = 0; d < 4; d++) {
            if(prev_d == d) continue;
            if(board[rx + dx[d]][ry + dy[d]] == '#' && board[bx + dx[d]][by + dy[d]] == '#') continue;

            n_rx = rx; n_ry = ry; r_move = 0; red_in = false;
            n_bx = bx; n_by = by; b_move = 0; blue_in = false;
            // move red
            while(board[n_rx + dx[d]][n_ry + dy[d]] != '#') {
                n_rx += dx[d];
                n_ry += dy[d];
                r_move++;

                if(board[n_rx][n_ry] == 'O') {
                    red_in = true;
                    break;
                }
            }
            // move blue
            while(board[n_bx + dx[d]][n_by + dy[d]] != '#') {
                n_bx += dx[d];
                n_by += dy[d];
                b_move++;

                if(board[n_bx][n_by] == 'O') {
                    blue_in = true;
                    break;
                }
            }

            if(red_in && !blue_in) {
                cout << count << '\n';
                return 0;
            }
            if(blue_in) continue;

            // if red and blue are in the same position
            // change the position of ball that moved more
            if(n_rx == n_bx && n_ry == n_by) {
                if(r_move < b_move) {
                    n_bx -= dx[d];
                    n_by -= dy[d];
                } else {
                    n_rx -= dx[d];
                    n_ry -= dy[d];
                }
            }
            q.push(make_pair(make_pair(make_pair(n_rx, n_ry), make_pair(n_bx, n_by)), make_pair(count, d)));
        }
    }

    cout << -1 << '\n';
    return 0;
}