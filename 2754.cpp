#include <iostream>
using namespace std;

int main() {
    string s;
    float point = 0.0;
    // "소수점 이하" 자릿수를 고정하겠다
    cout << fixed;
    // 1자리로 고정하겠다 (fixed 없이 사용할경우, 정수부를 합친 전체 자릿수가 고정됨)
    cout.precision(1);

    cin >> s;
    if(s.compare("F") == 0) cout << point;
    else {
        point = 4 - (s[0] - 'A');
        if(s[1] == '+') point += 0.3;
        else if(s[1] == '-') point -= 0.3;
        cout << point;
    }

    return 0;
}