#include <iostream>
#include <algorithm>
using namespace std;
#define lli long long int

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    int l, m, r, ll, mm, rr;
    lli ans = 3000000000, sum_of_end, sum;
    lli arr[5001];
    // input
    cin >> N;
    for(int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    // sort
    sort(arr, arr + N);
    // find
    l = 0; r = N - 1;
    while(l < r - 1) {
        sum_of_end = arr[l] + arr[r];
        m = lower_bound(arr + l + 1, arr + r - 1, -sum_of_end) - arr;
        // test near lower bound
        if(m - 1 > l) {
            m = (abs(sum_of_end + arr[m-1]) < abs(sum_of_end + arr[m])) ? m - 1 : m;
        }
        // sum of three
        sum = sum_of_end + arr[m];
        if(abs(ans) > abs(sum)) {
            ans = sum;
            ll = l;
            mm = m;
            rr = r;
        }

        if(sum > 0) r--;
        else if(sum < 0) l++;
        else break;
    }
    cout << arr[ll] << ' ' << arr[mm] << ' ' << arr[rr] << '\n';

    return 0;
}