#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, dp[31] = {0,};
    cin >> n;

    dp[2] = 3;
    for(int i = 4; i <= n; i += 2) {
        dp[i] += dp[i-2] * 3;
        for(int j = i - 4; j >= 2; j -= 2) {
            dp[i] += dp[j] * 2;
        }
        dp[i] += 2;
    }
    cout << dp[n] << '\n';
    return 0;
}