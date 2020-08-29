#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> x(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }

    ll res = INT_MIN, cur_res = 0;
    for (int i = 0; i < n; i++) {
        if (cur_res + x[i] > 0) {
            cur_res += x[i];
        }
        else {
            cur_res = 0;
        }
        res = max(cur_res, res);
    }

    cout << (!res ? *max_element(x.begin(), x.end()) : res) << endl;

}