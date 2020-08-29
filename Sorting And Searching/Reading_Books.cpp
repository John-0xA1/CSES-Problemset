#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> t(n);
    ll sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> t[i];
        sum += t[i];
    }

    cout << max(*max_element(t.begin(), t.end()) * 2LL, sum) << endl;
}