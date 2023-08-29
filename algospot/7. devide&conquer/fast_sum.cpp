#include <iostream>
using namespace std;
// 1 + 2 + ... + n
// = (1 + 2 + ... + n/2) + (n/2 + 1) + (n/2 + 2) + ... + (n/2 + n/2)
// = 2 * (1 + 2 + ... + n/2) + (n/2 + n/2 + ... + n/2)
// = 2 * (1 + 2 + ... + n/2) + (n/2)^2
long long int fast_sum(long long int n) {
    if(n == 1) return 1;
    if(n % 2 == 1) return n + fast_sum(n - 1);
    return 2 * fast_sum(n / 2) + n * n / 4;
}

int main() {
    int n;
    cin >> n;
    cout << fast_sum(n) << '\n';
    return 0;
}