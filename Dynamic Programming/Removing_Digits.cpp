#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxVal = 1e6 + 1;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> dp(n + 1, maxVal);
    dp[0] = 0;
    for (int i = 1; i <= n; i++) {
        for (char c : to_string(i)) {
            dp[i] = min(dp[i], dp[i - (c - '0')] + 1);
        }
    }

    cout << dp[n];
}