#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    long long sum = 0;
    int p[1001];

    cin >> N;
    for(int i = 0; i < N; i++) {
        cin >> p[i];
    }

    sort(p, p+N);
    sum = p[0];
    for(int i = 1; i < N; i++) {
        p[i] += p[i-1];
        sum += p[i];
    }
    cout << sum << '\n';

    return 0;
}