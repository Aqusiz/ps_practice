#include <iostream>
#include <algorithm>
using namespace std;
#define MAX 1000001

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N, ans = 0, *lb;
    int arr[MAX];
    int LIS[MAX] = {0,};

    cin >> N;
    for(int i = 0; i < N; i++) cin >> arr[i];
    
    for(int i = 0; i < N; i++) {
        lb = lower_bound(LIS, LIS+ans+1, arr[i]);
        *lb = arr[i];
        if(lb - LIS >= ans) ans = lb - LIS;
    }
    cout << ans << '\n';

    return 0;
}