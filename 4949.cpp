#include <iostream>
#include <stack>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string s;
    char temp;
    int flag, len;
    stack<char> st;

    while(true) {
        flag = 1;
        st = stack<char>();
        getline(cin, s);
        if(s.compare(".") == 0) break;

        len = s.size();
        for(int i = 0; i < len; i++) {
            if(s[i] == '(' || s[i] == '[') st.push(s[i]);
            else if(s[i] == ')') {
                if(st.empty() || st.top() != '(') {
                    flag = 0;
                    break;
                }
                st.pop();
            }
            else if(s[i] == ']') {
                if(st.empty() || st.top() != '[') {
                    flag = 0;
                    break;
                }
                st.pop();
            }
        }
        if(flag && st.empty()) cout << "yes\n";
        else cout << "no\n";
    }

    return 0;
}