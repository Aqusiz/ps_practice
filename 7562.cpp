#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int board[300][300];

int is_available(int i, int j, int I) {
    if(i < 0) return 0;
    if(j < 0) return 0;
    if(i > I - 1) return 0;
    if(j > I - 1) return 0;
    if(board[i][j] != 0) return 0;

    return 1;
}

void go_to(int i, int j, int path, queue<pair<int, int>>& q) {
    board[i][j] = path + 1;
    q.push(make_pair(i, j));
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    int I, x1, y1, x2, y2;

    queue<pair<int, int>> q;
    cin >> t;
    for(int i = 0; i < t; i++) {
        cin >> I >> x1 >> y1 >> x2 >> y2;
        for(int m = 0; m < I; m++) {
            for(int n = 0; n < I; n++) {
                board[m][n] = 0;
            }
        }
        q = queue<pair<int,int>>();
        q.push(make_pair(x1, y1));
        board[x1][y1] = 1;

        while(!q.empty()) {
            x1 = q.front().first;
            y1 = q.front().second;
            q.pop();
            if(x1 == x2 && y1 == y2) break;

            if(is_available(x1+1, y1+2, I)) go_to(x1+1, y1+2, board[x1][y1], q);
            if(is_available(x1+2, y1+1, I)) go_to(x1+2, y1+1, board[x1][y1], q);
            if(is_available(x1+1, y1-2, I)) go_to(x1+1, y1-2, board[x1][y1], q);
            if(is_available(x1+2, y1-1, I)) go_to(x1+2, y1-1, board[x1][y1], q);
            if(is_available(x1-1, y1+2, I)) go_to(x1-1, y1+2, board[x1][y1], q);
            if(is_available(x1-2, y1+1, I)) go_to(x1-2, y1+1, board[x1][y1], q);
            if(is_available(x1-1, y1-2, I)) go_to(x1-1, y1-2, board[x1][y1], q);
            if(is_available(x1-2, y1-1, I)) go_to(x1-2, y1-1, board[x1][y1], q);
        }

        cout << board[x2][y2] - 1 << endl;
    }

    return 0;
}