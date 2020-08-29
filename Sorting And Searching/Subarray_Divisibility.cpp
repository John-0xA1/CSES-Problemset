#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[i] %= n;
    }

    ll sum = 0, res = 0;
    unordered_map<ll, int> um;
    um.reserve(2 * 1e5 + 1);
    um[sum]++;
    for (int i = 0; i < n; i++) {
        sum = (sum + a[i] + n) % n;
        res += um[sum];
        um[sum]++;
    }

    cout << res << endl;
}