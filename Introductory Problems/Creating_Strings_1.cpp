#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;
    sort(s.begin(), s.end());

    int counter = 0;
    vector<string> res;
    do {
        counter++;
        res.push_back(s);
    } while (next_permutation(s.begin(), s.end()));

    cout << counter << endl;
    for (string &x : res) {
        cout << x << endl;
    }
}