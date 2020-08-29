#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> p(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }

    sort(p.begin(), p.end());
    ll median = p[n / 2 - 1];
    ll res = 0;
    for (int i = 0; i < n; i++) {
        res += abs(p[i] - median);
    }

    cout << res << endl;
}