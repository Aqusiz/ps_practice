#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N, p = 0, q = 0, arg;
    int queue[10001];
    string cmd;
    cin >> N;

    for(int i = 0; i < N; i++) {
        cin >> cmd;
        if(cmd.compare("push") == 0) {
            cin >> arg;
            queue[q++] = arg;
        }
        else if(cmd.compare("pop") == 0 && (p != q)) {
            cout << queue[p++] << '\n';
        }
        else if(cmd.compare("size") == 0) {
            cout << q - p << '\n';
        }
        else if(cmd.compare("empty") == 0) {
            arg = (p == q) ? 1 : 0;
            cout << arg << '\n';
        }
        else if(cmd.compare("front") == 0 && (p != q)) {
            cout << queue[p] << '\n';
        }
        else if(cmd.compare("back") == 0 && (p != q)) {
            cout << queue[q-1] << '\n';
        }
        else {
            cout << -1 << '\n';
        }
    }
}