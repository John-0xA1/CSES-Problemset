#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    set<int> res;
    int x;
    for (int i = 0; i < n; i++) {
        cin >> x;
        res.insert(x);
    }

    cout << res.size();
}