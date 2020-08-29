#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> used(n + 1, 0);
    int num;
    for (int i = 0; i < n - 1; i++) {
        cin >> num;
        used[num]++;
    }

    for (int i = 1; i <= n; i++) {
        if (!used[i]) {
            cout << i << endl;
            break;
        }
    }

}