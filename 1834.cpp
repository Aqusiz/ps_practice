#include <iostream>

using namespace std;

int main() {
    unsigned long long int n;
    unsigned long long int ans = 0;

    cin >> n;
    // x = n * i + i
    // i: [1, (n-1)]
    ans = (n + 1) * n * (n - 1) / 2;
    cout << ans << '\n';

    return 0;
}