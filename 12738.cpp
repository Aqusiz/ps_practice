#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N, len = 0;
    int *arr, *LIS, *p;

    cin >> N;
    arr = new int[N];
    LIS = new int[N];
    for(int i = 0; i < N; i++) {
        cin >> arr[i];
        LIS[i] = INT32_MAX;
    }

    for(int i = 0; i < N; i++) {
        p = lower_bound(LIS, LIS+len+1, arr[i]);
        *p = arr[i];
        if(p - LIS > len) len = p - LIS;
    }
    cout << len+1 << '\n';
    delete[] arr;
    delete[] LIS;
    return 0;
}