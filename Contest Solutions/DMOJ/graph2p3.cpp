#include <bits/stdc++.h>
using namespace std;

int id[1001];
int find(int x) {
    return id[x] < 0 ? x : (id[x] = find(id[x]));
}
void join(int x, int y) {
    if (id[x = find(x)] < id[y = find(y)]) {
        id[x] += id[y];
        id[y] = x;
    }
    else {
        id[y] += id[x];
        id[x] = y;
    }
}
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    int n, ans = 0;
    cin >> n;
    for (int i = 1; i <= n; i++) id[i] = -1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            int a;
            cin >> a;
            if (a && j > i) {
                if (find(i) == find(j)) ans++;
                else join(i, j);
            }
        }
    }
    cout << ans << "\n";
    return 0;
}
