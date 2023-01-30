#include <iostream>
using namespace std;
int st[100000], ed[100000];
int temp_st[100000], temp_ed[100000];

void merge(int p, int q, int r) {
    int i = p, j = q+1, k = p;
    // sort by end time
    // if end time is equal, then sort by start time
    while(i <= q && j <= r) {
        if(ed[i] < ed[j]) {
            temp_ed[k] = ed[i];
            temp_st[k++] = st[i++];
        } else if (ed[i] > ed[j]) {
            temp_ed[k] = ed[j];
            temp_st[k++] = st[j++];
        } else {
            if(st[i] <= st[j]) {
                temp_ed[k] = ed[i];
                temp_st[k++] = st[i++];
            } else {
                temp_ed[k] = ed[j];
                temp_st[k++] = st[j++];
            }
        }
    }
    while(i <= q) {
        temp_ed[k] = ed[i];
        temp_st[k++] = st[i++];
    }
    while(j <= r) {
        temp_ed[k] = ed[j];
        temp_st[k++] = st[j++];
    }
    for(k = p; k <= r; k++) {
        st[k] = temp_st[k];
        ed[k] = temp_ed[k];
    }
}

void mergesort(int p, int r) {
    int q;
    if(p >= r) return;

    q = (p + r) / 2;
    mergesort(p, q);
    mergesort(q+1, r);
    merge(p, q, r);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N, ans = 0, time = 0;

    cin >> N;
    for(int i = 0; i < N; i++) {
        cin >> st[i] >> ed[i];
    }
    mergesort(0, N-1);
    for(int i = 0; i < N; i++) {
        if(st[i] >= time) {
            ans++;
            time = ed[i];
        }
    }
    cout << ans << '\n';

    return 0;
}