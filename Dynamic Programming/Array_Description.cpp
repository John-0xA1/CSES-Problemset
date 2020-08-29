#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll modulo = 1e9 + 7;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<vector<int>> dp(n + 1, vector<int> (m + 1, 0));
    if (!a[0]) {
        for (int i = 1; i <= m; i++) {
            dp[0][i] = 1;
        }
    }
    dp[0][a[0]] = 1;

    for (int i = 1; i < n; i++) {
        if (a[i] == 0) {
            for (int j = 1; j <= m; j++) {

                if ((j - 1) >= 1) {
                    dp[i][j] += dp[i - 1][j - 1];
                    dp[i][j] %= modulo;
                }

                if ((j + 1) <= m) {
                    dp[i][j] += dp[i - 1][j + 1];
                    dp[i][j] %= modulo;
                }

                dp[i][j] += dp[i - 1][j];
                dp[i][j] %= modulo;
            }
        }
        else {
            if ((a[i] - 1) >= 1) {
                dp[i][a[i]] += dp[i - 1][a[i] - 1];
                dp[i][a[i]] %= modulo;
            }
            if ((a[i] + 1) <= m) {
                dp[i][a[i]] += dp[i - 1][a[i] + 1];
                dp[i][a[i]] %= modulo;
            }

            dp[i][a[i]] += dp[i - 1][a[i]];
            dp[i][a[i]] %= modulo;
        }
    }

    ll res = 0;
    for (int i = 1; i <= m; i++) {
        res += dp[n - 1][i];
        res %= modulo;
    }

    cout << res << endl;
}