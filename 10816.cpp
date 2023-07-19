#include <iostream>
#include <algorithm>
using namespace std;
int N, M;
int arr[500001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int card, *p;
    cin >> N;
    for(int i = 0; i < N; i++) cin >> arr[i];
    sort(arr, arr + N);
    cin >> M;
    for(int i = 0; i < M; i++) {
        cin >> card;
        p = lower_bound(arr, arr + N, card);
        if(*p != card) cout << 0;
        else cout << (lower_bound(arr, arr + N, card+1) - p);

        if(i != M - 1) cout << ' ';
    }

    return 0;
}