#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;
    vector<pair<int, int>> m(n);
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        m[i] = make_pair(b, a);
    }

    sort(m.begin(), m.end());
    int res = 0;
    multiset<int, greater<int>> ms;
    for (int i = 0; i < n; i++) {
        if (ms.empty()) {
            ms.insert(m[i].first);
            res++;
            continue;
        }

        auto x = ms.lower_bound(m[i].second);
        if (x != ms.end() && *x != ms.size()) {
            ms.erase(x);
            ms.insert(m[i].first);
            res++;
        }
        else {
            if (ms.size() < k) {
                ms.insert(m[i].first);
                res++;
            }
        }
    }

    cout << res << endl;
}