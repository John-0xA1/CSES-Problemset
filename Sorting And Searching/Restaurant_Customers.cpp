#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<pair<int, int>> customers;
    int a, b;
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        customers.push_back(make_pair(a, 1));
        customers.push_back(make_pair(b, 0));
    }

    sort(customers.begin(), customers.end());
    int res = 0, cur = 0;
    for (pair<int, int> x : customers) {
        if (x.second) {
            cur++;
        }
        else {
            cur--;
        }
        res = max(cur, res);
    }

    cout << res << endl;
}