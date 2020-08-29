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
    for (int i = 0; i < n; i++) {
        int target1 = x - a[i].first;
        for (int j = i + 1; j < n; j++) {
            int target2 = target1 - a[j].first;
            for (int ii = j + 1, ptr = n - 1; ii < ptr; ii++) {
                while (ii < ptr && a[ii].first + a[ptr].first > target2) {
                    ptr--;
                }
                if (a[ii].first + a[ptr].first == target2 && ii < ptr) {
                    cout << a[i].second << " " << a[j].second << " " << a[ii].second << " " << a[ptr].second << endl;
                    return 0;
                }
            }
        }
    }

    cout << "IMPOSSIBLE" << endl;
}