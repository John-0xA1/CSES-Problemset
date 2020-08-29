#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, a, b;
    cin >> n >> a >> b;
    vector<int> x(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }
    deque<int> dq, exdq;
    ll res = LONG_LONG_MIN;
    ll sum = 0, ex_sum = 0;
    for (int i = 0; i < n; i++) {
        if ((int)dq.size() + (int)exdq.size() < a) {
            sum += x[i];
            dq.push_front(x[i]);
        }
        else if ((int)dq.size() + (int)exdq.size() >= a && (int)dq.size() + (int)exdq.size() < b) {
            dq.push_front(x[i]);
            sum += x[i];
            sum -= dq.back();
            exdq.push_front(dq.back());
            ex_sum += dq.back();
            dq.pop_back();

            if (ex_sum < 0) {
                exdq.clear();
                ex_sum = 0;
            }
        }
        else {
            if (!exdq.empty()) {
                ex_sum -= exdq.back();
                exdq.pop_back();
                exdq.push_front(dq.back());
                ex_sum = max(dq.back() + ex_sum, (ll)dq.back());
            }

            if (ex_sum < 0) {
                exdq.clear();
                ex_sum = 0;
            }
            sum -= dq.back();
            dq.pop_back();
            dq.push_front(x[i]);
            sum += x[i];
        }

        if ((int)dq.size() >= a && (int)dq.size() <= b) {
            res = max(res, sum + ex_sum);
        }
    }

    cout << res << endl;
}