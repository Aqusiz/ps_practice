#include <iostream>
using namespace std;

int main() {
    int N, K, idx = 0, cnt = 0;
    int num[1001] = {};
    string ans = "<";
    cin >> N >> K;
    while(cnt < N) {
        for(int i = 0; i < K;) {
            idx++;
            if(idx > N) idx = 1;
            if(num[idx] == 0) i++;
        }
        num[idx] = 1;
        ans += to_string(idx) + ", ";
        cnt++;
    }
    ans = ans.substr(0, ans.size() - 2) + ">";
    cout << ans << endl;
}