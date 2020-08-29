#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int a, b;
        cin >> a >> b;

        if (b > a) {
            swap(a, b);
        }

        if (!a && !b) {
            cout << "YES" << endl;
            continue;
        }

        if (a >= 1 && b >= 1 && (a + b) % 3 == 0 && a <= 2 * b) {
            cout << "YES" << endl;
        }
        else {
            cout << "NO" << endl;
        }
    }

}