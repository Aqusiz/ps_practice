#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int i;
    int L, R, ans = 0, flag = 0;
    int L_digit[10], R_digit[10];
    cin >> L >> R;

    for(int i = 9; i >= 0; i--) {
        L_digit[i] = L % 10;
        R_digit[i] = R % 10;
        L /= 10;
        R /= 10;
    }

    for(i = 0; i < 10; i++) {
        if(L_digit[i] == R_digit[i]) {
            if(L_digit[i] == 8 && !flag) ans++;
        }
        else {
            if(flag) break;
            else flag = 1;
        }
    }
    cout << ans << '\n';

    return 0;
}