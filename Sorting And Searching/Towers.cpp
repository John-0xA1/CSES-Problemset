#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    multiset<int> ms;
    int res = 0;
    int k;
    for (int i = 0; i < n; i++) {
        cin >> k;
        if (ms.upper_bound(k) != ms.end() || *ms.upper_bound(k) != ms.size()) {
            ms.erase(ms.upper_bound(k));
            ms.insert(k);
        }
        else {
            ms.insert(k);
            res++;
        }
    }

    cout << res << endl;
}