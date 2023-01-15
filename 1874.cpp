#include <iostream>
#include <stack>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, idx = 1, temp;
    string ans;
    stack<int> s;

    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> temp;
        // when input(temp) is larger than the last pushed number(idx-1),
        // push all numbers in [idx, temp] and pop last one
        if(temp >= idx) {
            while(idx <= temp) {
                s.push(idx++);
                ans += "+\n";
            }
            s.pop();
            ans += "-\n";
        }
        // when input(temp) is equal to the top of the stack,
        // simply pop it
        else if(!s.empty() && temp == s.top()) {
            s.pop();
            ans += "-\n";
        }
        // else, it is impossible
        else {
            cout << "NO" << '\n';
            return 0;
        }
    }
    
    cout << ans;

    return 0;
}