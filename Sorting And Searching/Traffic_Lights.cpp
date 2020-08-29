#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int x, n;
    cin >> x >> n;
    set<int> pos;
    multiset<int> dist;
    pos.insert(0); pos.insert(x);

    int p;
    for (int i = 0; i < n; i++) {
        cin >> p;

        auto h = pos.lower_bound(p);
        auto l = prev(h);

        dist.insert(p - *l);
        dist.insert(*h - p);

        if (dist.find(*h - *l) != dist.end()) {
            dist.erase(dist.find(*h - *l));
        }

        pos.insert(p);

        cout << *dist.rbegin() << " ";
    }
}