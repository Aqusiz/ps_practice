#include <iostream>
#include <stack>
using namespace std;

int main() {
    int T, len, flag;
    string ps;
    stack<char> s;
    cin >> T;
    for(int i = 0; i < T; i++) {
        cin >> ps;
        len = ps.size();
        flag = 1;
        s = stack<char>();
        for(int j = 0; j < len; j++) {
            if(ps.at(j) == '(') s.push('(');
            else if(ps.at(j) == ')') {
                if(s.empty()) {
                    flag = 0;
                    break;
                }
                s.pop();
            }
        }
        if(flag && s.empty()) cout << "YES" << '\n';
        else cout << "NO" << '\n';
    }
}