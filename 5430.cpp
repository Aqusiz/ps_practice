#include <iostream>
#include <queue>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T, n, x, prev, curr;
    string p, arr, integer;
    deque<int> dq;

    cin >> T;
    for(int t = 0; t < T; t++) {
        bool reversed = false, flag = false;
        prev = 0, curr = 0;
        cin >> p;
        cin >> n;
        cin >> arr;
        // remove '[', ']'
        arr = arr.substr(1, arr.size() - 2);
        // split string into integers by ','
        curr = arr.find(",");
        for(int i = 0; i < n; i++) {
            integer = arr.substr(prev, curr - prev);
            dq.push_back(stoi(integer));
            prev = curr + 1;
            curr = arr.find(",", prev);
        } 

        for(int i = 0; i < p.size(); i++) {
            if(p[i] == 'R') reversed = !reversed;
            if(p[i] == 'D') {
                if(dq.size() == 0) {
                    cout << "error\n";
                    flag = true;
                    break;
                }
                if(reversed) dq.pop_back();
                else dq.pop_front();
            }
        }
        // error occured
        if(flag) continue;
        // no error, but deque is empty
        if(dq.empty()) {
            cout << "[]\n";
            continue;
        }
        
        p = "[";
        if(reversed) {
            p += to_string(dq.back()); dq.pop_back();
        } else {
            p += to_string(dq.front()); dq.pop_front();
        }
        while(!dq.empty()) {
            if(reversed) {
                p += "," + to_string(dq.back()); dq.pop_back();
            } else {
                p += "," + to_string(dq.front()); dq.pop_front();
            }
        }
        cout << p + "]\n";
    }
}