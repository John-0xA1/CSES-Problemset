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
        int target = x - a[i].first;
        for (int j = i + 1, ptr = n - 1; j < ptr; j++) {
            while (a[j].first + a[ptr].first > target && j < ptr) {
                ptr--;
            }
            if (a[j].first + a[ptr].first == target && j < ptr) {
                cout << a[i].second << " " << a[j].second << " " << a[ptr].second << endl;
                return 0;
            }
        }
    }

    cout << "IMPOSSIBLE";
}