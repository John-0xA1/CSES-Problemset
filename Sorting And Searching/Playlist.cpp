#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    unordered_map<int, int> um;
    um.reserve(2 * 1e6 + 1);
    int res = 0, cur = 0, pos = -1;
    int k;
    for (int i = 0; i < n; i++) {
        cin >> k;
        if (!um[k] || um[k] < pos) {
            um[k] = i + 1;
            cur++;
        }
        else {
            cur = (i + 1) - um[k];
            pos = um[k];
            um[k] = i + 1;
        }

        res = max(cur, res);
    }

    cout << res << endl;
}