#include <iostream>
#include <map>
#include <stack>
using namespace std;

int main() {
    string s;
    char before = ' ';
    stack<char> st;
    map<char, int> m;
    int ans = 0, multiplier = 1;

    m['('] = 2;
    m['['] = 3;
    cin >> s;
    for(int i = 0; i < s.size(); i++) {
        if(s[i] == '(' || s[i] == '[') {
            multiplier *= m[s[i]];
            st.push(s[i]);
        } else if( (s[i] == ')' && !st.empty() && st.top() == '(')
                || (s[i] == ']' && !st.empty() && st.top() == '[')) {
            multiplier /= m[st.top()];
            if(before != ')' && before != ']')
                ans += m[st.top()] * multiplier;
            st.pop();
        } else {
            cout << 0 << '\n';
            return 0;
        }
        before = s[i];
    }
    if(st.empty())
        cout << ans << '\n';
    else
        cout << 0 << '\n';
}