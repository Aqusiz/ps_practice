// 문제 해석: N을 이진수로 나타냈을 때, 1의 개수가 K개가 되려면 얼마의 수를 더해야 하는가?
#include <iostream>
using namespace std;

int bit_count(int n) {
    int i = 0;
    for(;n != 0; i++)
        n &= (n-1);
    return i;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N, K, ans = 0;
    cin >> N >> K;
    while(true) {
        if(bit_count(N++) <= K)
            break;
        ans++;
    }

    cout << ans << '\n';
    return 0;
}