#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, t;
    cin >> n >> t;
    vector<int> k(n);
    for (int i = 0; i < n; i++) {
        cin >> k[i];
    }

    ll l = 0, h = 1LL * *min_element(k.begin(), k.end()) * t;
    while (l < h) {
        ll m = (l + h) / 2;
        ll cur_sum = 0;
        for (int i = 0; i < n; i++) {
            cur_sum += m / k[i];
        }

        if (cur_sum >= t) {
            h = m;
        }
        else {
            l = m + 1;
        }
    }

    cout << l << endl;
}