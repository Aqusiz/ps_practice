#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;
#define MAX 1000001

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N, len = 0, *lb;
    int arr[MAX], LIS[MAX], pos[MAX];
    stack<int> ans;

    cin >> N;
    for(int i = 0; i < N; i++) {
        cin >> arr[i];
        LIS[i] = INT32_MIN;
    }

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
            ans.push(arr[i]);
            len--;
        }
    }
    // string을 이어 붙이는 방식으로는 너무 느림
    while(!ans.empty()) {
        cout << ans.top() << " ";
        ans.pop();
    }
    return 0;
}