#include <iostream>
using namespace std;
typedef unsigned long long ull;

int main() {
    ull L, r = 1, hash = 0;
    ull M = 1234567891;
    string s;
    cin >> L;
    cin >> s;
    for(int i = 0; i < L; i++) {
        hash = (hash + ((int)(s[i] - 'a' + 1) * r) % M) % M;
        r = ((r%M) * 31) % M;
    }
    cout << hash << endl;

    return 0;
}