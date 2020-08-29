#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll modulo = 1e9 + 7;

int power(ll base, int exp) {
    int res = 1;
    base %= modulo;

    if (!base) {
        return 0;
    }

    while (exp > 0) {
        if (exp & 1) {
            res = (res * base) % modulo;
        }

        exp >>= 1;
        base = (base * base) % modulo;
    }

    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    cout << power(2, n);
}