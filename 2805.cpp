#include <iostream>
using namespace std;
typedef unsigned long long ull;

ull tri_min(ull a, ull b, ull c) {
    if(a <= b && a <= c) return a;
    else if(b <= a && b <= c) return b;
    else if(c <= a && c <= b) return c;

    return a;
}

int main() {
    int N;
    ull M, left = 0, mid = 0, right = 0, len = 0;
    ull tree[1000000];

    cin >> N >> M;
    for(int i = 0; i < N; i++) {
        cin >> tree[i];
        if(tree[i] > right) right = tree[i];
    }

    while(left <= right) {
        mid = (left + right) / 2;
        len = 0;

        for(int i = 0; i < N; i++) {
            if(tree[i] > mid) len += (tree[i] - mid);
        }
        if(len >= M) left = mid + 1;
        else right = mid - 1;
    }
    cout << tri_min(left, mid, right) << '\n';

    return 0;
}