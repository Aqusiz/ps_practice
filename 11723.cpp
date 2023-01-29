#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int M, x;
    int s[21] = {0,};
    string op;

    cin >> M;

    for(int i = 0; i < M; i++) {
        cin >> op;

        if(op.compare("add") == 0) {
            cin >> x;
            s[x] = 1;
        }
        else if(op.compare("remove") == 0) {
            cin >> x;
            s[x] = 0;
        }
        else if(op.compare("check") == 0) {
            cin >> x;
            cout << s[x] << '\n';
        }
        else if(op.compare("toggle") == 0) {
            cin >> x;
            s[x] = 1 - s[x];
        }
        else if(op.compare("all") == 0) {
            for(int j = 1; j <= 20; j++) {
                s[j] = 1;
            }
        }
        else if(op.compare("empty") == 0) {
            for(int j = 1; j <= 20; j++) {
                s[j] = 0;
            }
        }

    }

    return 0;
}