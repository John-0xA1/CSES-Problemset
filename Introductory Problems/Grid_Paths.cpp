#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

string s;
vector<vector<int>> grid(7, vector<int> (7, 0));
int res = 0;

bool validate(int row, int col) {
    return ((row >= 0 && row < 7) && (col >= 0 && col < 7) && !grid[row][col]);
}

void solve(int row, int col, int move = 0) {
    if (row == 6 && col == 0) {
        if (move == 48) {
            res++;
        }
        return;
    }

    grid[row][col] = 1;
    if (s[move] == '?' || s[move] == 'L') {
        if (col && !grid[row][col - 1]) {
            if (!(!validate(row, col - 2) && validate(row - 1, col - 1) && validate(row + 1, col - 1))) {
                solve(row, col - 1, move + 1);
            }
        }
    }
    if (s[move] == '?' || s[move] == 'R') {
        if (col < 6 && !grid[row][col + 1]) {
            if (!(!validate(row, col + 2) && validate(row - 1, col + 1) && validate(row + 1, col + 1))) {
                solve(row, col + 1, move + 1);
            }
        }
    }
    if (s[move] == '?' || s[move] == 'U') {
        if (row && !grid[row - 1][col]) {
            if (!(!validate(row - 2, col) && validate(row - 1, col - 1) && validate(row - 1, col + 1))) {
                solve(row - 1, col, move + 1);
            }
        }
    }
    if (s[move] == '?' || s[move] == 'D') {
        if (row < 6 && !grid[row + 1][col]) {
            if (!(!validate(row + 2, col) && validate(row + 1, col - 1) && validate(row + 1, col + 1))) {
                solve(row + 1, col, move + 1);
            }
        }
    }

    grid[row][col] = 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> s;
    solve(0, 0);
    cout << res << endl;
}