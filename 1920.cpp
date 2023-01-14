#include <iostream>
using namespace std;
int b[100001];

void merge(int p, int r, int q, int* a) {
    int i = p, j = r + 1, k = p;
    while(i <= r && j <= q) {
        if(a[i] < a[j])
            b[k++] = a[i++];
        else
            b[k++] = a[j++];
    }
    while(i <= r) {
        b[k++] = a[i++];
    }
    while(j <= q) {
        b[k++] = a[j++];
    }
    for(int l = p; l <= q; l++) {
        a[l] = b[l];
    } 
    return;
}

void merge_sort(int p, int q, int* a) {
    int r = (p + q) / 2;
    if(p >= q) return;

    merge_sort(p, r, a);
    merge_sort(r+1, q, a);
    merge(p, r, q, a);
}

int binary_search(int target, int p, int q, int* a) {
    int r;
    while(p <= q) {
        r = (p + q) / 2;
        if(a[r] == target) return 1;

        if(a[r] > target) q = r - 1;
        else p = r + 1;
    }
    return 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N, M, num;
    int A[100001] = {};

    cin >> N;
    for(int i = 0; i < N; i++)
        cin >> A[i];
    cin >> M;
    
    merge_sort(0, N-1, A);
    
    for(int i = 0; i < M; i++) {
        cin >> num;
        cout << binary_search(num, 0, N-1, A) << '\n';
    }

    return 0;
}