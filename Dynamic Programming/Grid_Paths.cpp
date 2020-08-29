#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll modulo = 1e9 + 7;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<string> grid(n);
    for (int i = 0; i < n; i++) {
        cin >> grid[i];
    }

    vector<vector<int>> dp(n + 1, vector<int> (n + 1, 0));
    grid[0][0] == '.' ? dp[0][0] = 1 : dp[0][0] = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == '.') {
                if (i > 0) {
                    dp[i][j] += dp[i - 1][j];
                    dp[i][j] %= modulo;
                }
                if (j > 0) {
                    dp[i][j] += dp[i][j - 1];
                    dp[i][j] %= modulo;
                }
            }
        }
    }

    cout << dp[n - 1][n - 1];
}