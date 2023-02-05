#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N, K, ans = 0;
    int a[1000000];

    cin >> N >> K;
    for(int i = 0; i < N; i++) {
        cin >> a[i];
    }
    while(K > 0) {
        if(a[--N] > K) continue;
        ans += K / a[N];
        K %= a[N];
    }
    cout << ans << '\n';

    return 0;
}