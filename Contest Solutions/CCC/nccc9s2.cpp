#include <bits/stdc++.h>
using namespace std;

int n;
long long ans = 0;
string s;
vector<int> v;
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> n >> s;
    for (int i = 0; i < 2 * n; i++) if (s[i] == 'U') v.push_back(i);
    for (int i = 0; i < n; i++) {
        if (v[i] > 2 * i) ans += v[i] - 2 * i - 1;
        else ans += 2 * i - v[i] + 1;
    }
    cout << ans << "\n";
    return 0;
}
