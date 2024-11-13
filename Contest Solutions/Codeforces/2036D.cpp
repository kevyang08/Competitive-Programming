#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll INFL = 0x3f3f3f3f3f3f3f3f;

int t, n, m;
string grid[1000];
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> t;
    while (t--) {
        cin >> n >> m;
        int ans = 0;
        for (int i = 0; i < n; i++) cin >> grid[i];
        for (int i = 0; i < min(n, m)/2; i++) {
            vector<char> v;
            int r = i, c = i, dr = 0, dc = 1;
            v.push_back(grid[r][c]);
            ++c;
            while (r != i || c != i) {
                v.push_back(grid[r][c]);
                if (v.size() > 3 && v[v.size() - 4] == '1' && v[v.size() - 3] == '5' && v[v.size() - 2] == '4' && v.back() == '3') ++ans;
                if (r == i && c == m - i - 1) dr = 1, dc = 0;
                else if (r == n - i - 1 && c == m - i - 1) dr = 0, dc = -1;
                else if (r == n - i - 1 && c == i) dr = -1, dc = 0;
                r += dr, c += dc;
            }
            for (int i = v.size() - 3; i < v.size(); i++) if (v[i] == '1' && v[(i + 1)%v.size()] == '5' && v[(i + 2)%v.size()] == '4' && v[(i + 3)%v.size()] == '3') ++ans;
        }
        cout << ans << "\n";
    }
    return 0;
}