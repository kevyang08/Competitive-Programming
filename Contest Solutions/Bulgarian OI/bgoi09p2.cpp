#include <bits/stdc++.h>
using namespace std;

int n, p, id[100001], ans[2];
bool used[100001];
int find(int x) {
    return id[x] < 0 ? x : (id[x] = find(id[x]));
}
void join(int a, int b) {
    a = find(a); b = find(b);
    id[a] += id[b];
    id[b] = a;
    used[b] = false;
}
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    for (int bruh = 0; bruh < 2; bruh++) {
        memset(id, -1, sizeof(id));
        memset(used, true, sizeof(used));
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> p;
            if (find(p) != find(i)) join(p, i);
        }
        for (int i = 1; i <= n; i++) if (used[i]) ans[bruh]++;
    }
    cout << ans[0] << " " << ans[1] << "\n";
    return 0;
}
