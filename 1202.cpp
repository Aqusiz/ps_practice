#include <iostream>
#include <set>
#include <queue>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, k, m, v, c;
    unsigned long long ret = 0;
    priority_queue<pair<int, int> > vm;
    multiset<int> bags;
    multiset<int>::iterator bag;

    cin >> n >> k;
    for(int i = 0; i < n; i++) {
        cin >> m >> v;
        vm.push(make_pair(v, m));
    }
    for(int i = 0; i < k; i++) {
        cin >> c;
        bags.insert(c);    
    }

    while(!vm.empty() && !bags.empty()) {
        v = vm.top().first;
        m = vm.top().second;
        vm.pop();
        // lower_bound in <algorithm> takes O(n) time to load data structure
        // use member function!!
        bag = bags.lower_bound(m);
        if(bag == bags.end()) continue;

        ret += (unsigned long long)v;
        bags.erase(bag);
    }
    cout << ret << '\n';
    return 0;
}