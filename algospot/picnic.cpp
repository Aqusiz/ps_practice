// https://www.algospot.com/judge/problem/read/PICNIC
// exhaustive search
#include <iostream>
#include <vector>

using namespace std;

int c, n, m;
bool is_friend[10][10];

int count_pairs(bool picked[10]) {
    // 짝이 없는 첫 번째 사람을 찾는다 (오름차순으로만 짝을 지어 중복 count 방지)
    int first = -1;
    for(int i = 0; i < n; i++) {
        if(!picked[i]) {
            first = i;
            break;
        }
    }
    if(first == -1) return 1;

    int ret = 0;
    for(int i = first + 1; i < n; i++) {
        if(!picked[i] && is_friend[first][i]) {
            picked[first] = picked[i] = true;
            ret += count_pairs(picked);
            picked[first] = picked[i] = false;
        }
    }
    return ret;
}

int main() {
    int a, b;
    cin >> c;
    for(int t = 0; t < c; t++) {
        cin >> n >> m;
        bool picked[10] = {false,};
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                is_friend[i][j] = false;
            }
        }
        for(int i = 0; i < m; i++) {
            cin >> a >> b;
            is_friend[a][b] = true;
            is_friend[b][a] = true;
        }
        cout << count_pairs(picked) << '\n';
    }
}