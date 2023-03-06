#include <iostream>
using namespace std;
// recursive building LCS string
void print(int i, int j, string& a, string& b, int dp[1001][1001]) {
    if(dp[i][j] == 0) return;
    
    if(a[i-1] == b[j-1]) {
        print(i-1, j-1, a, b, dp);
        cout << a[i-1];
    } else {
        (dp[i-1][j] > dp[i][j-1]) ? print(i-1, j, a, b, dp) : print(i, j-1, a, b, dp);
    }
}

int main() {
    int len_a, len_b;
    int dp[1001][1001] = {0,};
    string a, b;
    // input
    cin >> a >> b;
    len_a = a.size();
    len_b = b.size();
    // dp, finding length
    for(int i = 1; i <= len_a; i++) {
        for(int j = 1; j <= len_b; j++) {
            if(a[i-1] == b[j-1]) dp[i][j] = dp[i-1][j-1] + 1;
            else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
    cout << dp[len_a][len_b] << '\n';
    if(dp[len_a][len_b] != 0) print(len_a, len_b, a, b, dp);
    return 0;
}