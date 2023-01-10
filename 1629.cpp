#include <iostream>
using namespace std;

long long answer(long long a, long long b, long long c) {
    long long ans;
    if(b == 1) return a % c;

    ans = answer(a, b/2, c) % c;
    if(b % 2) return ((ans * ans)%c * a%c) % c;
    else return (ans * ans) % c;
}

int main() {
    long long A, B, C;
    cin >> A >> B >> C;

    cout << answer(A, B, C) << endl;
    return 0;
}