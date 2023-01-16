#include <iostream>
#include <queue>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t, n, m, temp, high_prio, cnt;
    int prio_cnt[10] = {};
    queue<int> q;
    cin >> t;

    for(int l = 0; l < t; l++) {
        // init for every test case
        high_prio = 0; cnt = 0;
        q = queue<int>();
        for(int i = 1; i <= 9; i++) {
            prio_cnt[i] = 0;
        }

        cin >> n >> m;
        for(int i = 0; i < n; i++) {
            cin >> temp;
            q.push(temp);
            prio_cnt[temp]++;
            // set highest priority
            if(temp > high_prio) high_prio = temp;
        }

        while(true) {
            temp = q.front();
            // end when the target is printed (m: position of the target)
            if(m == 0 && high_prio == temp) {
                cout << cnt + 1 << '\n';
                break;
            }
            // there exists higher priority in queue
            if(temp < high_prio) {
                q.pop(); q.push(temp);
                m--;
            } else {    // or else
                q.pop();
                m--; cnt++;
                prio_cnt[high_prio]--;
                // determine the highest priority
                for(int j = 9; j >= 1; j--) {
                    if(prio_cnt[j] != 0) {
                        high_prio = j;
                        break;
                    }
                }
            }
            // when target is moved to the back of queue
            if(m < 0) {
                m = q.size() - 1;
            }
        }
    }

    return 0;
}