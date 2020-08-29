#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<pair<int, int>> x(n);
    for (int i = 0; i < n; i++) {
        int xi;
        cin >> xi;
        x[i] = make_pair(xi, i + 1);
    }

    stack<pair<int, int>> st;
    for (int i = 0; i < n; i++) {
        while (!st.empty() && st.top().first >= x[i].first) {
            st.pop();
        }
        cout << (st.empty() ? 0 : st.top().second) << " ";

        st.push(x[i]);
    }
}