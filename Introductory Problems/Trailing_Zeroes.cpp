#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    int res = 0;
    for (int i = 5; n / i >= 1; i *= 5) {
        res += n / i;
    }

    cout << res << endl;
}