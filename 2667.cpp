#include <iostream>
using namespace std;
int N;
int map[2][26][26];     // map[0] = map / map[1] = visited (0 = no visited)
int cnt[625];

int is_available(int i, int j) {
    if(i < 0) return 0;
    if(j < 0) return 0;
    if(i > N-1) return 0;
    if(j > N-1) return 0;
    if(map[0][i][j] == 0) return 0;
    if(map[1][i][j] != 0) return 0;

    return 1;
}

void traverse(int i, int j, int count) {
    map[1][i][j] = count;
    cnt[count]++;

    if(is_available(i - 1, j)) traverse(i - 1, j, count);
    if(is_available(i, j - 1)) traverse(i, j - 1, count);
    if(is_available(i + 1, j)) traverse(i + 1, j, count);
    if(is_available(i, j + 1)) traverse(i, j + 1, count);
    return;
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    char temp;
    int count = 0;
    // input and init
    cin >> N;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cin >> temp;
            map[0][i][j] = (int)(temp - '0');
            map[1][i][j] = 0;
        }
    }
    for(int i = 0; i < 625; i++) {
        cnt[i] = 0;
    }
    // DFS from not visited coord
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            if(map[0][i][j] == 0) continue;     // skip 0
            if(map[1][i][j] != 0) continue;     // skip visited
            traverse(i, j, ++count);
        }
    }
    // simple bubble sort in [1, count]
    for(int i = 1; i < count; i++) {
        for(int j = 1; j <= count-i; j++) {
            if(cnt[j] > cnt[j + 1]) swap(&cnt[j], &cnt[j + 1]);
        }
    }

    cout << count << '\n';
    for(int i = 1; i <= count; i++) {
        cout << cnt[i] << '\n';
    }
    return 0;
}