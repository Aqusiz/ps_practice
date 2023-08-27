// https://www.algospot.com/judge/problem/read/CLOCKSYNC
// exhaustive search, 난이도 중
#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

int C;
const int INF = 31;
const vector<int> clocks_to_switch[10] = {
    {0, 1, 2}, {3, 7, 9, 11}, {4, 10, 14, 15}, {0, 4, 5, 6, 7}, {6, 7, 8, 10 ,12},
    {0, 2, 14, 15}, {3, 14, 15}, {4, 5, 7, 14, 15}, {1, 2, 3, 4, 5}, {3, 4, 5, 9, 13}
};

bool is_all_12(vector<int>& clocks) {
    for(int i = 0; i < 16; i++) {
        if(clocks[i] != 12) return false;
    }
    return true;
}

void push_switch(vector<int>& clocks, int switch_idx) {
    int clock_idx;
    for(int i = 0; i < clocks_to_switch[switch_idx].size(); i++) {
        clock_idx = clocks_to_switch[switch_idx][i];

        clocks[clock_idx] += 3;
        if(clocks[clock_idx] > 12) {
            clocks[clock_idx] -= 12;
        }
    }
}

int count(vector<int> clocks, vector<int> pushed_cnt, int idx) {
    // 모든 시계가 12시이면, 뒤를 더 눌러볼 것도 없이 누른 횟수 반환
    if(is_all_12(clocks)) return accumulate(pushed_cnt.begin(), pushed_cnt.end(), 0);
    // 0~9번 스위치를 모두 돌고 나서도 답이 없으므로 반환
    else if(idx == 10) return INF;

    int ret = INF, temp;
    // idx번 스위치를 0번, 1번, 2번, 3번 눌렀을 때의 count 값 중 최소값을 찾는다.
    for(int i = 0; i < 4; i++) {
        ret = min(ret, count(clocks, pushed_cnt, idx+1));
        push_switch(clocks, idx);
        pushed_cnt[idx]++;
    }

    return ret;
}

int main() {
    cin >> C;
    for(int c = 0; c < C; c++) {
        vector<int> clocks = vector<int>(16, 0);
        for(int i = 0; i < 16; i++) {
            cin >> clocks[i];
        }
        int ans = count(clocks, vector<int>(10, 0), 0);
        cout << ((ans == INF) ? -1 : ans) << '\n';
    }

    return 0;
}