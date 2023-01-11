#include <iostream>
using namespace std;

int main() {
    int a, ans = 0;
    for(int i = 0; i < 5; i++) {
        cin >> a;
        ans += a * a;
    }
    cout << ans % 10 << endl;
}