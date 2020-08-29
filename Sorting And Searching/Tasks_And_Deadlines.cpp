#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<pair<int, int>> d(n);
    int a, b;
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        d[i] = make_pair(a, b);
    }

    sort(d.begin(), d.end());

    ll cur_time = 0;
    ll res = 0;
    for (int i = 0; i < n; i++) {
        res += d[i].second - (cur_time + d[i].first);
        cur_time += d[i].first;
    }

    cout << res << endl;
}