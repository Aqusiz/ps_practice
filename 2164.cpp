#include <iostream>
using namespace std;

int main() {
    int N, p, q;
    int card[1000001];
    cin >> N;
    for(int i = 0; i < N; i++) {
        card[i] = i;
    }
    p = 0; q = N - 1;
    while(p != q) {
        card[p++] = -1;
        card[++q] = card[p++];
    }
    cout << card[p] + 1 << endl;

    return 0;
}