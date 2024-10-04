#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

/*
what is the significance of d <= 10?

- each element will only be iterated over once for each value of d
- everything else will only be used to connect with other segments
- use dsu, probably small to large merging
    - use path compression, small to large is too annoying
*/

int t, n, m, a, d, k, id[20][200001], aid[200001], nxt[200001];
int find(int x) {
    if (aid[x] < 0) return x;
    aid[x] = find(aid[x]);
    if (nxt[x] > nxt[aid[x]]) nxt[aid[x]] = nxt[x];
    else nxt[x] = nxt[aid[x]];
    return aid[x];
}
void join(int x, int y) {
    aid[(x = find(x))] = (y = find(y));
    if (nxt[x] > nxt[y]) nxt[y] = nxt[x];
    else nxt[x] = nxt[y];
}
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> t;
    while (t--) {
        cin >> n >> m;
        for (int i = 1; i <= m; i++) nxt[i] = -1, aid[i] = -1;
        for (int i = 1; i <= n; i++) 
            for (int k = 1; k <= 10; k++) 
                id[k][i] = -1;
        for (int i = 1; i <= m; i++) {
            cin >> a >> d >> k;
            int idx = a, r = a + d * k;
            nxt[i] = r + d;
            while (idx <= r) {
                if (id[d][idx] != -1) {
                    int tmp = nxt[find(id[d][idx])];
                    join(id[d][idx], i);
                    idx = tmp;
                    continue;
                }
                id[d][idx] = i;
                idx += d;
            }
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= 10; j++) {
                if (id[j][i] == -1) continue;
                for (int k = j + 1; k <= 10; k++) {
                    if (id[k][i] == -1) continue;
                    if (find(id[j][i]) != find(id[k][i])) join(id[j][i], id[k][i]);
                }
            }
        }
        int cnt = 0;
        for (int i = 1; i <= m; i++) cnt += (aid[i] == -1);
        for (int i = 1; i <= n; i++) {
            int thing = 1;
            for (int k = 1; k <= 10; k++) if (id[k][i] != -1) thing = 0;
            cnt += thing;
        }
        cout << cnt << "\n";
    }
    return 0;
}