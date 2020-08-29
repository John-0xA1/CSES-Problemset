#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    unordered_map<ll, int> um;
    um.reserve(2 * 1e5 + 1);
    ll sum = 0, res = 0;
    um[sum]++;
    for (int i = 0; i < n; i++) {
        sum += (a[i]);
        res += um[sum - x];
        um[sum]++;
    }

    cout << res << endl;
}