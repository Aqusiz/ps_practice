#include <iostream>
#include <stack>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int K, temp, sum = 0;
    stack<int> s;

    cin >> K;

    for(int i = 0; i < K; i++) {
        cin >> temp;

        if(temp == 0) s.pop();
        else s.push(temp);
    }

    while(!s.empty()) {
        sum += s.top();
        s.pop();
    }

    cout << sum << '\n';

    return 0;
}