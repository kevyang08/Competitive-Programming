#include <bits/stdc++.h>
using namespace std;

int n, m, x, y, z, arr[17][150005], a[150005], tree[600005];
vector<pair<pair<int, int>, int>> v(m);
int gcd(int a, int b) {return a%b == 0 ? b : gcd(b, a%b);}
int lcm(int a, int b) {return a/gcd(a, b) * b;}
void build(int l, int r, int idx) {
    if (l == r) {
        tree[idx] = a[l];
        return;
    }
    int m = (l + r)/2;
    build(l, m, 2 * idx);
    build(m + 1, r, 2 * idx + 1);
    tree[idx] = gcd(tree[2 * idx], tree[2 * idx + 1]);
}
int query(int ql, int qr, int l, int r, int idx) {
    if (l > qr || r < ql) return 720720;
    if (l >= ql && r <= qr) return tree[idx];
    int m = (l + r)/2;
    return gcd(query(ql, qr, l, m, 2 * idx), query(ql, qr, m + 1, r, 2 * idx + 1));
}
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> x >> y >> z;
        arr[z][x]++;
        arr[z][y + 1]--;
        v.push_back({{x, y}, z});
    }
    for (int i = 1; i <= n; i++) {
        int temp = 1;
        for (int j = 1; j < 17; j++) {
            arr[j][i] += arr[j][i - 1];
            if (arr[j][i]) temp = lcm(temp, j);
        }
        a[i] = temp;
    }
    build(1, n, 1);
    for (int i = 0; i < m; i++) {
        if (query(v[i].first.first, v[i].first.second, 1, n, 1) != v[i].second) {
            cout << "Impossible\n";
            return 0;
        }
    }
    for (int i = 1; i < n; i++) cout << a[i] << " ";
    cout << a[n] << "\n";
}
