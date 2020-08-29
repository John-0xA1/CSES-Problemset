#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, x;
    cin >> n >> x;
    vector<pair<int, int>> a(n);
    int ai;
    for (int i = 0; i < n; i++) {
        cin >> ai;
        a[i] = make_pair(ai, i + 1);
    }

    sort(a.begin(), a.end());

    for (int i = 0, j = n - 1; i < j; i++) {
        while (a[i].first + a[j].first > x && i < j) {
            j--;
        }
        if (a[i].first + a[j].first == x && i < j) {
            cout << a[i].second << " " << a[j].second;
            return 0;
        }
    }

    cout << "IMPOSSIBLE" << endl;
}