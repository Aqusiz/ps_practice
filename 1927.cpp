#include <iostream>
using namespace std;

void swap(int* a, int* b) {
    int temp = *a; *a = *b; *b = temp;
    return;
}

void h_delete(int* h, int cnt) {
    int root = 1, left = 2, right = 3;
    h[root] = 0;
    if(cnt <= 1) return;
    swap(&h[root], &h[cnt]);
    // child가 없을 때까지 반복
    while(h[left] != 0) {
        // 오른쪽 child가 없을 때
        if(h[right] == 0) {
            // 왼쪽 child와 자기 비교
            if(h[left] >= h[root]) return;
            swap(&h[left], &h[root]);
            root = left;
        }
        // 오른쪽 child가 있을 때
        else {
            // 양 쪽 child와 자기 비교. 둘 다 자기보다 크면 끝
            if(h[left] >= h[root] && h[right] >= h[root]) return;
            if(h[left] > h[right]) {
                swap(&h[right], &h[root]);
                root = right;
            } else {
                swap(&h[left], &h[root]);
                root = left;
            }
        }
        left = 2 * root;
        right = left + 1;
    }
    return;
}

void h_insert(int x, int* h, int cnt) {
    int idx = cnt + 1, root = idx / 2;
    h[idx] = x;
    // 최상위 root까지 반복
    while(root > 0) {
        if(h[idx] < h[root]) {
            swap(&h[idx], &h[root]);
            idx = root;
            root = idx / 2;
        } else return;
    }
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N, x, cnt = 0;
    int h[200002] = {0,};

    cin >> N;
    for(int i = 0; i < N; i++) {
        cin >> x;
        if(x == 0) {
            cout << h[1] << '\n';
            h_delete(h, cnt);
            if(cnt != 0) cnt--;
        } else h_insert(x, h, cnt++);
    }

    return 0;
}