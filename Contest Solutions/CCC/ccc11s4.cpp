#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll INFL = 0x3f3f3f3f3f3f3f3f;

int adj[20][20];
bool vis[20];
int dfs(int i, int mn) {
    if (!mn) return 0;
    if (i == 17) return mn;
    vis[i] = true;
    for (int j = 1; j <= 17; j++) {
        if (!adj[i][j] || vis[j]) continue;
        int cur = dfs(j, min(adj[i][j], mn));
        if (cur) {
            adj[i][j] -= cur;
            adj[j][i] += cur;
            vis[i] = false;
            return cur;
        }
    }
    vis[i] = false;
    return 0;
}
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    for (int i = 1; i <= 8; i++) cin >> adj[0][i]; // O-, O+, A-, A+, B-, B+, AB-, AB+
    for (int i = 9; i <= 16; i++) cin >> adj[i][17];
    for (int i = 9; i <= 16; i++) adj[1][i] = min(adj[0][1], adj[i][17]); // edges for O-
    for (int i = 10; i <= 16; i += 2) adj[2][i] = min(adj[0][2], adj[i][17]); // edges for O+
    for (int i = 11; i <= 12; i++) adj[3][i] = min(adj[0][3], adj[i][17]);
    for (int i = 15; i <= 16; i++) adj[3][i] = min(adj[0][3], adj[i][17]); // edges for A-
    adj[4][12] = min(adj[0][4], adj[12][17]); adj[4][16] = min(adj[0][4], adj[16][17]); // edges for A+
    for (int i = 13; i <= 16; i++) adj[5][i] = min(adj[0][5], adj[i][17]); // edges for B-
    adj[6][14] = min(adj[0][6], adj[14][17]); adj[6][16] = min(adj[0][6], adj[16][17]); // edges for B+
    for (int i = 15; i <= 16; i++) adj[7][i] = min(adj[0][7], adj[i][17]); // edges for AB-
    adj[8][16] = min(adj[0][8], adj[16][17]); // edge for AB+
    int mx = 0, cur = INF;
    while (cur) {
        cur = dfs(0, INF);
        mx += cur;
    }
    cout << mx << "\n";
    return 0;
}