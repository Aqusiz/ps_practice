#include <iostream>
using namespace std;

int main() {
    int num, minus_flag = 0, sum = 0;
    char op;
    string n;

    while(cin >> op) {
        if(op >= '0' && op <= '9') {
            n += op;
        } else {
            num = stoi(n);
            if(minus_flag) sum -= num;
            else sum += num;
            
            if(op == '-') minus_flag = 1;
            n = "";
        }
    }
    // take last number
    num = stoi(n);
    if(minus_flag) sum -= num;
    else sum += num;

    cout << sum;

    return 0;
}