#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);


    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int res = 0;
    ll sum = 0;
    for (int i = 0, j = 0; i < n; i++) {
        while (sum < x && j < n) {
            sum += a[j];
            j++;
        }

        res += (sum == x);
        sum -= a[i];
    }

    cout << res << endl;
}