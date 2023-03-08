#include <iostream>
#include <climits>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N, p1, p2, ans1, ans2;
    int *arr;
    long long sum, min = LLONG_MAX;

    cin >> N;
    arr = new int[N];
    for(int i = 0; i < N; i++) cin >> arr[i];

    p1 = 0; p2 = N-1;
    while(p1 < p2) {
        sum = arr[p1] + arr[p2];
        if(abs(sum) <= abs(min)) {
            ans1 = p1;
            ans2 = p2;
            min = sum;
            if(sum == 0) break;
        }
        if(sum > 0) p2--;
        else p1++;
    }
    cout << arr[ans1] << " " << arr[ans2] << '\n';
    delete[] arr;
    return 0;
}