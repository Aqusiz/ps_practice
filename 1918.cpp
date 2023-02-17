#include <iostream>
#include <stack>
using namespace std;

string to_postfix(string expr) {
    int idx = -1, cnt = 0, length = expr.size();
    string a, b, ret;
    stack<string> opd, opr;

    while(idx < length) {
        idx++;
        // push operator
        if(expr[idx] == '*' || expr[idx] == '/' || expr[idx] == '+' || expr[idx] == '-') {
            opr.push(expr.substr(idx, 1));
            continue;
        }
        // push operand
        if(expr[idx] >= 'A' && expr[idx] <= 'Z') {
            opd.push(expr.substr(idx, 1));
        }
        // push parenthesis
        // recursive transformation
        else if(expr[idx] == '(') {
            cnt = 1; a = "";
            while(cnt > 0) {
                idx++;
                if(expr[idx] == '(') cnt++;
                else if(expr[idx] == ')') cnt--;
                a += expr[idx];
            }
            // remove last ")"
            opd.push(to_postfix(a.substr(0, a.size() - 1)));
        }
        // if the last pushed operator is "*" or "/", then do the operation first
        // else, nvm
        if(opr.empty() || opr.top().compare("+") == 0 || opr.top().compare("-") == 0) continue;
        b = opd.top(); opd.pop();
        a = opd.top(); opd.pop();
        opd.push(a + b + opr.top()); opr.pop();
    }
    // compose all operands and operators(+, -)
    while(!opr.empty()) {
        ret = opd.top() + opr.top() + ret;
        opd.pop(); opr.pop();
    }
    return opd.top() + ret;
}

int main() {
    string expr;

    cin >> expr;
    cout << to_postfix(expr) << '\n';
    
    return 0;
}