#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n, m, k;
vector<string> grid;
vector<vector<char>> ans;
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> n >> m >> k;
    vector<string> grid(n);
    vector<vector<char>> ans(n, vector<char>(m, '.'));
    for (int i = 0; i < n; i++) {
        cin >> grid[i];
        int thing = -0x3f3f3f3f;
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 'A') thing = j;
            else if (grid[i][j] == 'B') ans[i][j] = (j - thing <= k ? 'N' : 'Y');
        }
        thing = 0x3f3f3f3f;
        for (int j = m - 1; j >= 0; j--) {
            if (grid[i][j] == 'B') thing = true;
            else if (grid[i][j] == 'A') ans[i][j] = (thing - j <= k ? 'N' : 'Y');
        }
    }
    for (int i = 0; i < n; i++) {
        for (char c : ans[i]) cout << c;
        cout << "\n";
    }
    return 0;
}