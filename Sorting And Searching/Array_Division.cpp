#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;
    k--;
    vector<int> x(n);
    ll total = 0;
    for (int i = 0; i < n; i++) {
        cin >> x[i];
        total += x[i];
    }

    ll l = *max_element(x.begin(), x.end()), h = total;
    while (l < h) {
        ll mid = (l + h) / 2;
        int subArrays = 0;
        ll cur_sum = 0;
        for (int i = 0; i < n; i++) {
            if (cur_sum + x[i] > mid) {
                cur_sum = 0;
                subArrays++;
            }
            cur_sum += x[i];
        }

        if (subArrays > k) {
            l = mid + 1;
        }
        else {
            h = mid;
        }
    }

    cout << l << endl;

}