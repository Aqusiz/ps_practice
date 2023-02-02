#include <iostream>
using namespace std;

void swap(int *a, int *b) {
    int temp = *a; *a = * b; *b = temp; return;
}

void h_delete(int* heap, int size) {
    int root = 1, left = 2, right = 3;
    heap[root] = 0;
    swap(&heap[root], &heap[size]);

    while(heap[left] != 0) {
        if(heap[right] == 0) {
            if(heap[left] <= heap[root]) return;
            swap(&heap[left], &heap[root]);
            root = left;
        } else {
            if(heap[left] <= heap[root] && heap[right] <= heap[root]) return;
            if(heap[left] > heap[right]) {
                swap(&heap[left], &heap[root]);
                root = left;
            } else {
                swap(&heap[right], &heap[root]);
                root = right;
            }
        }
        left = root * 2;
        right = left + 1;
    }
    return;
}

void h_insert(int x, int* heap, int size) {
    int idx = size + 1, root = idx / 2;
    heap[idx] = x;

    while(root > 0) {
        if(heap[root] >= heap[idx]) return;
        swap(&heap[root], &heap[idx]);
        idx = root;
        root = idx / 2;
    }
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, x, size = 0;
    int heap[200002] = {0,};

    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> x;
        if(x == 0) {
            cout << heap[1] << '\n';
            h_delete(heap, size);
            if(size > 0) size--;
        } else h_insert(x, heap, size++);
    }

    return 0;
}