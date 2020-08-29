#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    if (n > 3 || n == 1) {
        for (int i = n; i >= 1; i--) {
            if (i & 1) {
                cout << i << " ";
            }
        }
        for (int i = n; i >= 1; i--) {
            if (!(i & 1)) {
                cout << i << " ";
            }
        }
    }
    else {
        cout << "NO SOLUTION" << endl;
    }
}