#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll modulo = 1e9 + 7;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, x;
    cin >> n >> x;
    vector<int> coins(n);
    for (int i = 0; i < n; i++) {
        cin >> coins[i];
    }

    vector<int> dp(x + 1, 0);
    dp[0] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 1; j <= x; j++) {
            if (j - coins[i] >= 0) {
                dp[j] += dp[j - coins[i]];
                dp[j] %= modulo;
            }
        }
    }

    cout << dp[x];
}