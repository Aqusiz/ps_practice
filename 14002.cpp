#include <iostream>
#include <algorithm>
using namespace std;
#define MAX 1001

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N, len = 0, *lb;
    int arr[MAX], LIS[MAX] = {0,}, pos[MAX] = {0,};
    string LIS_str;

    cin >> N;
    for(int i = 0; i < N; i++) cin >> arr[i];

    for(int i = 0; i < N; i++) {
        lb = lower_bound(LIS, LIS+len+1, arr[i]);
        *lb = arr[i];
        pos[i] = lb - LIS;
        if(lb - LIS >= len) len = lb - LIS;
    }
    cout << len << '\n';
    for(int i = N-1; i >= 0; i--) {
        if(len == 0) break;
        if(pos[i] == len) {
            LIS_str = to_string(arr[i]) + " " + LIS_str;
            len--;
        }
    }
    cout << LIS_str << '\n';
    return 0;
}