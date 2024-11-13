#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll INFL = 0x3f3f3f3f3f3f3f3f;

int t, n, p[3][200001];
char bruh[3] = {'q', 'k', 'j'};
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> t;
    while (t--) {
        cin >> n;
        bool ans = false;
        vector<vector<int>> v(3, vector<int>(n));
        vector<int> cur(3);
        vector<vector<int>> idx(3, vector<int>(n + 1));
        vector<vector<bool>> vis(3, vector<bool>(n + 1));
        vector<priority_queue<int>> pqv(3, priority_queue<int>());
        vector<vector<int>> nxtk(3, vector<int>(n + 1, -1));
        vector<vector<int>> nxtc(3, vector<int>(n + 1, -1));
        for (int i = 0; i < 3; i++) {
            iota(v[i].begin(), v[i].end(), 1);
            for (int j = 1; j <= n; j++) cin >> p[i][j];
            sort(v[i].begin(), v[i].end(), [&](auto a, auto b) { // reverse
                return p[i][a] > p[i][b];
            });
            for (int j = 0; j < n; j++) idx[i][v[i][j]] = j;
        }
        priority_queue<pair<int, int>> pq;
        pq.push({n, 0});
        vis[0][idx[0][n]] = vis[1][idx[1][n]] = vis[2][idx[2][n]];
        while (!pq.empty()) {
            auto [c, k] = pq.top(); pq.pop();
            for (int i = 0; i < 3; i++) {
                if (cur[i] > idx[i][c]) continue;
                while (cur[i] <= idx[i][c]) pqv[i].push(-v[i][cur[i]++]);
                while (!pqv[i].empty() && -pqv[i].top() < c) {
                    int tmp = -pqv[i].top(); pqv[i].pop();
                    
                    // cout << i << " " << c << " " << tmp << " bruh\n";

                    vis[i][tmp] = true;

                    nxtk[i][tmp] = k;
                    nxtc[i][tmp] = c;

                    pq.push({tmp, i});
                    if (tmp == 1) {
                        ans = true;
                        break;
                    }
                }
            }
        }
        if (ans) {
            cout << "YES\n";
            int k = -1, nk = -1, c = -1;
            vector<pair<char, int>> va;
            for (int i = 0; i < 3; i++) if (vis[i][1]) k = i, nk = nxtk[i][1], c = nxtc[i][1];
            while (c != -1 && k != -1) {
                // cout << bruh[c] << " " << v[c][id] << "\n";
                va.push_back({bruh[k], c});
                k = nk, nk = nxtk[k][c], c = nxtc[k][c];
            }
            cout << va.size() << "\n";
            for (auto &[a, b] : va) cout << a << " " << b << "\n";
        }
        else cout << "NO\n";
    }
    return 0;
}