#include <bits/stdc++.h>
using namespace std;

int n, cnt = 0;
string s;
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> n >> s;
    for (int i = 0; i < 2 * n; i++) if (i > 0 && s[i - 1] == 'I' && s[i] == 'U') cnt++;
    cout << n - cnt << "\n";
    return 0;
}
