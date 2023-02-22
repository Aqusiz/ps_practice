#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N, S;
    int i = 0, j = 1, sum = 0, ans = 0;
    int arr[100001] = {0,}, psum[100001] = {0,};

    cin >> N >> S;
    for(int k = 1; k <= N; k++) {
        cin >> arr[k];
        psum[k] = psum[k-1] + arr[k];
    }

    while(i <= N && j <= N) {
        sum = psum[j] - psum[i];
        if(sum < S) {
            j++;
        }
        else {
            if(ans == 0 || ans > j - i) ans = j - i;
            i++;
        }
    }
    cout << ans << '\n';
    return 0;
}