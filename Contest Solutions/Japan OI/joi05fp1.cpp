#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll INFL = 0x3f3f3f3f3f3f3f3f;

int n, m, a, cnt[101];
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> n >> m;
    vector<int> v(m);
    iota(v.begin(), v.end(), 1);
    while (n--) {
        for (int j = 1; j <= m; j++) {
            cin >> a;
            if (a) ++cnt[j];
        }
    }
    sort(v.begin(), v.end(), [&](auto a, auto b) {
        return cnt[a] != cnt[b] ? cnt[a] > cnt[b] : a < b;
    });
    for (int i : v) cout << i << " ";
    cout << "\n";
    return 0;
}