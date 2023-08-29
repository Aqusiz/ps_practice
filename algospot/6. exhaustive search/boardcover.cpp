// https://www.algospot.com/judge/problem/read/BOARDCOVER
// exhaustive search
#include <iostream>
#include <vector>

using namespace std;

int C, H, W;
char board[20][20];
// 가장 위, 가장 왼쪽 자리에 블록을 놓는다고 가정할 때 놓을 수 있는 블록의 상대 위치 (dy, dx)
int block_type[4][3][2] = {
    {{0, 0}, {0, 1}, {1, 1}},
    {{0, 0}, {0, 1}, {1, 0}},
    {{0, 0}, {1, 0}, {1, 1}},
    {{0, 0}, {1, 0}, {1, -1}}
};

bool is_in_bound(int y, int x) {
    if(y < 0 || x < 0 || y >= H || x >= W) return false;
    else return true;
}
// 해당 포지션에 해당 블록을 놓을 수 있는지 없는지 체크한 후
// 놓을 수 없다면 false
// 놓을 수 있다면 블록을 놓고 true
bool set(int y, int x, int block) {
    int ny, nx;
    for(int i = 0; i < 3; i++) {
        ny = y + block_type[block][i][0];
        nx = x + block_type[block][i][1];

        if(!is_in_bound(ny, nx) || board[ny][nx] == '#') return false;
    }

    for(int i = 0; i < 3; i++) {
        ny = y + block_type[block][i][0];
        nx = x + block_type[block][i][1];
        board[ny][nx] = '#';
    }
    return true;
}
// 놓았던 블록 다시 되돌려 놓기
void unset(int y, int x, int block) {
    int ny, nx;
    for(int i = 0; i < 3; i++) {
        ny = y + block_type[block][i][0];
        nx = x + block_type[block][i][1];

        board[ny][nx] = '.';
    }
}

int count_cases() {
    // 가장 위, 가장 왼쪽 position 탐색
    int first_y = -1, first_x = -1;
    for(int i = 0; i < H; i++) {
        for(int j = 0; j < W; j++) {
            if(board[i][j] == '.') {
                first_y = i;
                first_x = j;
                break;
            }
        }
        if(first_y != -1) break;
    }
    // 빈 공간 없으면 count
    if(first_y == -1) return 1;

    int ret = 0;
    for(int i = 0; i < 4; i++) {
        if(set(first_y, first_x, i)) {
            ret += count_cases();
            unset(first_y, first_x, i);
        }
    }

    return ret;
}

int main() {
    cin >> C;
    for(int c = 0; c < C; c++) {
        cin >> H >> W;
        for(int i = 0; i < H; i++) {
            for(int j = 0; j < W; j++) {
                cin >> board[i][j];
            }
        }

        cout << count_cases() << '\n';
    }

    return 0;
}