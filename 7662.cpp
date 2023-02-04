#include <iostream>
#include <queue>
using namespace std;

class dual_priority_queue {
private:
    int size;
    priority_queue<int> maxh, deleted_minh;
    priority_queue<int, vector<int>, greater<int> > minh, deleted_maxh;

    void remove_trash() {
        while(!deleted_maxh.empty() && minh.top() == deleted_maxh.top()) {
            minh.pop();
            deleted_maxh.pop();
        }
        while(!deleted_minh.empty() && maxh.top() == deleted_minh.top()) {
            maxh.pop();
            deleted_minh.pop();
        }
    }

public:
    dual_priority_queue() {
        size = 0;
        maxh = priority_queue<int>();
        deleted_minh = priority_queue<int>();
        minh = priority_queue<int, vector<int>, greater<int> >();
        deleted_maxh = priority_queue<int, vector<int>, greater<int> >();
    }

    void push(int x) {
        maxh.push(x);
        minh.push(x);
        size++;
    }

    void pop_min() {
        if(size == 0) return;
        deleted_minh.push(minh.top());
        minh.pop();
        size--;
        remove_trash();
    }

    void pop_max() {
        if(size == 0) return;
        deleted_maxh.push(maxh.top());
        maxh.pop();
        size--;
        remove_trash();
    }

    void print() {
        string ans;
        ans = (size == 0) ? "EMPTY" : to_string(maxh.top()) + " " + to_string(minh.top());
        cout << ans << '\n';
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T, K, n;
    char op;
    dual_priority_queue dpq;

    cin >> T;
    for(int t = 0; t < T; t++) {
        dpq = dual_priority_queue();

        cin >> K;
        for(int k = 0; k < K; k++) {
            cin >> op >> n;
            if(op == 'I') {
                dpq.push(n);
            }
            else if(op == 'D') {
                if(n == 1) dpq.pop_max();
                else dpq.pop_min();
            }
        }
        dpq.print();
    }
}