#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxVal = 1e5 + 1;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> coins(n);
    for (int i = 0; i < n; i++) {
        cin >> coins[i];
    }

    vector<vector<int>> dp(n + 1, vector<int> (maxVal + 1, 0));
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= maxVal; j++) {
            dp[i][j] = dp[i - 1][j];
            if (j - coins[i - 1] >= 0) {
                dp[i][j] += dp[i - 1][j - coins[i - 1]];
            }
        }
    }

    vector<int> res;
    for (int i = 1; i <= maxVal; i++) {
        if (dp[n][i]) {
            res.push_back(i);
        }
    }

    cout << res.size() << "\n";
    for (int x : res) {
        cout << x << " ";
    }
}