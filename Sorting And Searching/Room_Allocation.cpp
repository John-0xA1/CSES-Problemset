#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<pair<pair<int, int>, int>> c(n);
    int a, b;
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        c[i] = make_pair(make_pair(a, b), i);
    }

    sort(c.begin(), c.end());
    multiset<pair<int, int>> ms;
    vector<int> res(n);
    int cur_room = 1;
    for (int i = 0; i < n; i++) {
        if (ms.empty()) {
            ms.insert(make_pair(c[i].first.second, cur_room));
            res[c[i].second] = cur_room;
        }
        else {
            auto f = *ms.begin();
            if (c[i].first.first > f.first) {
                pair<int, int> p = make_pair(c[i].first.second, f.second);
                ms.erase(f);
                ms.insert(p);
                res[c[i].second] = p.second;
            }
            else {
                ms.insert(make_pair(c[i].first.second, ++cur_room));
                res[c[i].second] = cur_room;
            }
        }
    }

    cout << *max_element(res.begin(), res.end()) << endl;
    for (int x : res) {
        cout << x << " ";
    }
}