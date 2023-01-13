#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N, p = 10000, q = 10001, arg;
    int deque[20002];
    string cmd;
    cin >> N;

    for(int i = 0; i < N; i++) {
        cin >> cmd;
        if(cmd.compare("push_front") == 0) {
            cin >> arg;
            deque[p--] = arg;
        }
        else if(cmd.compare("push_back") == 0) {
            cin >> arg;
            deque[q++] = arg;
        }
        else if(cmd.compare("pop_front") == 0 && (q-p > 1)) {
            cout << deque[++p] << '\n';
        }
        else if(cmd.compare("pop_back") == 0 && (q-p > 1)) {
            cout << deque[--q] << '\n';
        }
        else if(cmd.compare("size") == 0) {
            cout << q - p - 1<< '\n';
        }
        else if(cmd.compare("empty") == 0) {
            arg = (q - p == 1) ? 1 : 0;
            cout << arg << '\n';
        }
        else if(cmd.compare("front") == 0 && (q - p > 1)) {
            cout << deque[p + 1] << '\n';
        }
        else if(cmd.compare("back") == 0 && (q - p > 1)) {
            cout << deque[q - 1] << '\n';
        }
        else {
            cout << -1 << '\n';
        }
    }
}