#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, k;
    cin >> n >> m >> k;

    vector<int> a(n), b(m);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < m; i++) {
        cin >> b[i];
    }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    int j = 0;
    int res = 0;
    for (int i = 0; i < n; i++) {
        while (j < m && a[i] - b[j] > k) {
            j++;
        }
        if (j < m && b[j] - a[i] <= k) {
            res++;
            j++;
        }
    }

    cout << res << endl;
}