#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    for (ll i = 1; i <= n; i++) {
        cout << 1LL * (((i * i) * ((i * i) - 1)) / 2 - 4 * (i - 1) * (i - 2)) << endl;
    }
}