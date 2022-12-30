#include <iostream>
using namespace std;

int pow(int x, int y) {
    int ans = 1;
    for(int i = 0; i < y; i++)
        ans *= x;
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N, r, c, temp, ans = 0;
    int quadrant;
    cin >> N >> r >> c;
    temp = pow(2, N);
    while(temp != 1) {
        temp /= 2;
        quadrant = 2 * (r / temp) + (c / temp);             // quadrant: 0 | 1
        ans += temp * temp * quadrant;                      //           2 | 3
        if(r >= temp) r -= temp;
        if(c >= temp) c -= temp;
    }
    cout << ans << '\n';

    return 0;
}