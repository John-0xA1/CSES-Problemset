#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<pair<int, int>> m(n);
    int a, b;
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        m[i] = make_pair(b, a);
    }

    sort(m.begin(), m.end());
    int cur_movie = 0, res = 0;
    for (int i = 0; i < n; i++) {
        if (cur_movie <= m[i].second) {
            res++;
            cur_movie = m[i].first;
        }
    }

    cout << res << endl;
}