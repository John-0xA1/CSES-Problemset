#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;
    int n = s.size();
    vector<int> letters(26, 0);
    for (char c : s) {
        letters[c - 'A']++;
    }

    int c_odds = 0;
    for (int i : letters) {
        if (i && i & 1) {
            c_odds++;
        }
    }

    if (c_odds > 1) {
        cout << "NO SOLUTION" << endl;
    }
    else {
        string front = "";
        for (int i = 0; i < 26; i++) {
            if (letters[i] && !(letters[i] & 1)) {
                string substr = string(letters[i] / 2, 'A' + i);
                front += substr;
            }
        }
        string back = front;
        reverse(back.begin(), back.end());

        if (n & 1) {
            for (int i = 0; i < 26; i++) {
                if (letters[i] && letters[i] & 1) {
                    string substr = string(letters[i], 'A' + i);
                    front += substr;
                }
            }
        }
        cout << front + back << endl;
    }
}