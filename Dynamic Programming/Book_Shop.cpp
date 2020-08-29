#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll modulo = 1e9 + 7;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, x;
    cin >> n >> x;
    vector<int> price(n), pages(n);
    for (int i = 0; i < n; i++) {
        cin >> price[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> pages[i];
    }

    vector<int> dp(x + 1, 0);

    for (int i = 0; i < n; i++) {
        for (int j = x; j >= 0; j--) {
            if (j - price[i] >= 0) {
                dp[j] = max(dp[j], dp[j - price[i]] + pages[i]);
            }
        }
    }

    cout << dp[x] << endl;
}