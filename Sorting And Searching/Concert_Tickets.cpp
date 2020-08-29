#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    multiset<int, greater<int>> tickets;
    vector<int> customers(m);
    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;
        tickets.insert(t);
    }

    for (int i = 0; i < m; i++) {
        cin >> customers[i];
    }

    tickets.insert(-1);
    for (int i = 0; i < m; i++) {
        auto t = tickets.lower_bound(customers[i]);
        if (*t > 0) {
            tickets.erase(t);
        }
        cout << *t << endl;
    }
}