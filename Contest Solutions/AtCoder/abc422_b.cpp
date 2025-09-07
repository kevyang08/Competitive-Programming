#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll INFL = 0x3f3f3f3f3f3f3f3f;
// const int M = 998244353
const int M = 1e9 + 7;

int h, w, dr[4] = {1, 0, -1, 0}, dc[4] = {0, 1, 0, -1};
string s[20];
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> h >> w;
    for (int i = 0; i < h; i++) cin >> s[i];
    bool ans = true;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (s[i][j] == '.') continue;
            int cnt = 0;
            for (int k = 0; k < 4; k++) {
                if (i + dr[k] >= 0 && i + dr[k] < h && j + dc[k] >= 0 && j + dc[k] < w && s[i + dr[k]][j + dc[k]] == '#') ++cnt;
            }
            ans &= (cnt > 0 && cnt%2 == 0);
        }
    }
    cout << (ans ? "Yes\n" : "No\n");
    return 0;
}