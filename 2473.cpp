#include <iostream>
#include <algorithm>
using namespace std;
#define lli long long int

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    int l, m, r;
    lli ans = 3000000000, sum_of_two, sum_of_three;
    lli arr[5001];
    // input
    cin >> N;
    for(int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    // sort
    sort(arr, arr + N);
    // find
    for(int i = 0; i < N - 2; i++) {
        for(int j = i + 1; j < N - 1; j++) {
            sum_of_two = arr[i] + arr[j];
            int k = lower_bound(arr + j + 1, arr + N - 1, -sum_of_two) - arr;

            if(k - 1 > j) {
                k = ( abs(sum_of_two + arr[k-1]) < abs(sum_of_two + arr[k]) ) ? k-1 : k;
            }

            sum_of_three = sum_of_two + arr[k];
            if(abs(ans) > abs(sum_of_three)) {
                ans = sum_of_three;
                l = i;
                r = k;
                m = j;
            }
        }
    }
    cout << arr[l] << ' ' << arr[m] << ' ' << arr[r] << '\n';

    return 0;
}