#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> p(n);
    ll total = 0;
    for (int i = 0; i < n; i++) {
        cin >> p[i];
        total += p[i];
    }

    ll res = INT_MAX;
    for (int i = 0; i < (1 << n); i++) {
        ll cur_sum = 0;
        for (int j = 0; j < n; j++) {
            if (i & (1 << j)) {
                cur_sum += p[j];
            }
        }

        res = min(res, abs((total - cur_sum) - cur_sum));
    }
    cout << res << endl;
}