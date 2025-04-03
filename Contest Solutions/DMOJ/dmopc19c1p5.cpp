#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll INFL = 0x3f3f3f3f3f3f3f3f;

const int mask = (1 << 5) - 1;

int n, k, sz, a = -1, b = -1;
vector<vector<int>> adj;
vector<int> ind, out;
string s;
vector<int> ans;
void dfs(int i) {
    while (!adj[i].empty()) {
        int j = adj[i].back();
        adj[i].pop_back();
        dfs((i << 5)%sz | j);
    }
    ans.push_back(i & mask);
}
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> n >> k;
    sz = 1 << (k - 1) * 5;
    adj.resize(sz);
    ind.resize(sz);
    out.resize(sz);
    for (int i = 0; i < n; i++) {
        cin >> s;
        if (k == 1) cout << s;
        else {
            int u = 0, v = s[k - 1] - 'a' + 1;
            for (int j = 0; j < k - 1; j++) {
                u <<= 5;
                u |= s[j] - 'a' + 1;
            }
            adj[u].push_back(v);
            ++out[u]; ++ind[(u << 5)%sz | v];
        }
    }
    if (k == 1) {
        cout << "\n";
        return 0;
    }
    for (int i = 0; i < sz; i++) {
        if (ind[i] == out[i]) continue;
        if (ind[i] == out[i] - 1) {
            if (a == -1) a = i;
            else {
                cout << "-1\n";
                return 0;
            }
        }
        else if (ind[i] == out[i] + 1) {
            if (b == -1) b = i;
            else {
                cout << "-1\n";
                return 0;
            }
        }
        else {
            cout << "-1\n";
            return 0;
        }
    }
    if ((a == -1 || b == -1) && a != b) {
        cout << "-1\n";
        return 0;
    }
    if (a == -1) {
        for (int i = 0; i < sz; i++) if (out[i]) {
            a = i;
            break;
        }
    }
    dfs(a);
    if (ans.size() != n + 1) {
        cout << "-1\n";
        return 0;
    }
    while (a >>= 5) ans.push_back(a & mask);
    while (!ans.empty()) {
        cout << (char)(ans.back() + 'a' - 1);
        ans.pop_back();
    }
    cout << "\n";
    return 0;
}