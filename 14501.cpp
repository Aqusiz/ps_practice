#include <iostream>
#include <vector>

using namespace std;

int N;
int t[16], p[16];

int dfs(int curr_day, int value) {
    if(curr_day >= N) return value;

    int with_curr = 0, wo_curr = 0;
    
    if(curr_day + t[curr_day] <= N) with_curr = dfs(curr_day + t[curr_day], value + p[curr_day]);
    wo_curr = dfs(curr_day + 1, value);

    return max(with_curr, wo_curr);
}

int solve() {
    int ans = dfs(0, 0);
    return ans;
}

int main() {
    cin >> N;
    for(int i = 0; i < N; i++) {
        cin >> t[i] >> p[i];
    }

    cout << solve() << '\n';
    return 0;
}