#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    if (n % 4 == 0 || (n - 3) % 4 == 0) {
        vector<int> a, b;
        if (n & 1) {
            a.push_back(1); a.push_back(2); b.push_back(3);
            for (int i = 3; i < n; i += 4) {
                a.push_back(i + 1); a.push_back(i + 4);
                b.push_back(i + 2); b.push_back(i + 3);
            }
        }
        else {
            a.push_back(1); a.push_back(4); b.push_back(2); b.push_back(3);
            for (int i = 4; i < n; i+= 4) {
                a.push_back(i + 1); a.push_back(i + 4);
                b.push_back(i + 2); b.push_back(i + 3);
            }
        }
        cout << "YES" << endl;
        cout << a.size() << endl;
        for (int i : a) {
            cout << i << " ";
        }
        cout << "\n" << b.size() << endl;
        for (int i : b) {
            cout << i << " ";
        }

    }
    else {
        cout << "NO" << endl;
    }
}