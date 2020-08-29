#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, x;
    cin >> n >> x;
    vector<int> p(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }

    sort(p.begin(), p.end());
    int res = 0;
    int i = 0, j = n - 1;
    while (i <= j) {
        if (p[i] + p[j] > x) {
            j--;
            res++;
            continue;
        }
        i++;
        j--;
        res++;
    }

    cout << res << endl;
}