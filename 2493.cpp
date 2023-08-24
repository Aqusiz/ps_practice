#include <iostream>
#include <stack>

using namespace std;

int n;
int towers[500001], ans[500001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    stack<int> st;

    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> towers[i];
        ans[i] = 0;
    }
    for(int i = n; i >= 1; i--) {
        while(!st.empty() && towers[st.top()] <= towers[i]) {
            ans[st.top()] = i;
            st.pop();
        }
        st.push(i);
    }

    for(int i = 1; i <= n; i++) {
        cout << ans[i] << ' ';
    } cout << '\n';

    return 0;
}