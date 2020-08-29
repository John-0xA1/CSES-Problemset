#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxVal = 5 * 1e3 + 1;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);


    string x, y;
    cin >> x >> y;
    int n = x.size(); int m = y.size();

    vector<vector<int>> dp(n + 1, vector<int> (m + 1, maxVal));

    for (int i = 0; i <= n; i++) {
        dp[i][0] = i;
    }
    for (int i = 0; i <= m; i++) {
        dp[0][i] = i;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            dp[i][j] = min(dp[i - 1][j] + 1, min(dp[i][j - 1] + 1, dp[i - 1][j - 1] + (x[i - 1] != y[j - 1])));
        }
    }

    cout << dp[n][m];
}