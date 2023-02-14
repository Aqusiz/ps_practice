#include <iostream>
using namespace std;

int digit(int n) {
    int ret = 0;
    if(n == 0) return 1;

    while(n > 0) {
        ret++;
        n /= 10;
    }
    return ret;
}

bool check(int n, int* num) {
    int x;
    if(n < 0) return false;
    if(n == 0) return 1 - num[0];

    while(n > 0) {
        x = n % 10;
        if(num[x] == 1) return false;
        n /= 10;
    }
    return true;
}

int main() {
    int N, M, temp, ans1, ans2, i;
    int num[10] = {0,};

    cin >> N >> M;
    for(i = 0; i < M; i++) {
        cin >> temp;
        num[temp] = 1;
    }
    // +/- 만 눌러서 N에 도착하는 경우
    ans1 = abs(N - 100);
    if(M == 10) {
        cout << ans1 << '\n';
        return 0;
    }
    // 숫자 버튼을 누르는 경우
    i = 0;
    while(true) {
        // N - i가 먼저인 이유: 자릿수가 줄어드는 경우, 눌러야 하는 버튼의 수가 적어질 수 있기 때문
        // 예: N = 1555, M = 3, 0 1 9 -> 888일 때, 667 + 3 = 670 / 2222일 때, 667 + 4 = 671
        if(check(N - i, num)) {
            temp = N - i;
            ans2 = i;
            break;
        }
        if(check(N + i, num)) {
            temp = N + i;
            ans2 = i;
            break;
        }
        i++;
    }
    ans2 += digit(temp);

    if(ans1 > ans2) cout << ans2 << '\n';
    else cout << ans1 << '\n';

    return 0;
}