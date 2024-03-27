#include <iostream>
#include <vector>
using namespace std;
int N, B, C;
vector<int> A;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long ans = 0;
    cin >> N;
    A.assign(N, 0);
    for(int i = 0; i < N; i++)
        cin >> A[i];
    cin >> B >> C;

    ans = N;    // 총감독관 각 방마다 1명씩
    for(int i = 0; i < N; i++) {
        A[i] -= B;
        if(A[i] <= 0) continue;
        ans += (A[i] + C - 1) / C;
    }

    cout << ans << '\n';
    return 0;
}