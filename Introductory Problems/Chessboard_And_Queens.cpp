#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

vector<string> board(8);
vector<int> col(8, 0), diag1(16, 0), diag2(16, 0);
int res = 0;

void solve(int row) {
    if (row == 8) {
        res++;
        return;
    }

    for (int i = 0; i < 8; i++) {
        if (board[row][i] == '.') {
            if (col[i] || diag1[row + i] || diag2[row - i + 7]) {
                continue;
            }
            col[i] = diag1[row + i] = diag2[row - i + 7] = 1;
            solve(row + 1);
            col[i] = diag1[row + i] = diag2[row - i + 7] = 0;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    for (int i = 0; i < 8; i++) {
        cin >> board[i];
    }

    solve(0);
    cout << res << endl;
}