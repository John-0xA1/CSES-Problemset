#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        ll y, x;
        cin >> y >> x;

        if (y > x) {
            if (y & 1) {
                cout << ((y - 1) * (y - 1)) + x << endl;
            }
            else {
                cout << (y * y) + 1 - x << endl;
            }
        }
        else {
            if (x & 1) {
                cout << (x * x) + 1 - y << endl;
            }
            else {
                cout << ((x - 1) * (x - 1)) + y << endl;
            }
        }
    }
}