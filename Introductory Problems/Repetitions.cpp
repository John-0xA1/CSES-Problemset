#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;
    int n = s.size();

    int res = 1, cur_res = 1;
    for (int i = 0; i < n - 1; i++) {
        if (s[i] == s[i + 1]) {
            cur_res++;
            res = max(res, cur_res);
        }
        else {
            cur_res = 1;
        }
    }

    cout << res << endl;
}