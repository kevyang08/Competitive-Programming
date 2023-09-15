#include <bits/stdc++.h>
using namespace std;

int n, a[100001], bit[100001], cnt = 0;
vector<int> v;
unordered_map<int, int> idx;
double ans = 0;
void update(int i) {
    for (; i > 0; i -= (i & -i)) bit[i]++;
}
int query(int i) {
    int res = 0;
    for (; i <= n; i += (i & -i)) res += bit[i];
    return res;
}
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        v.push_back(a[i]);
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < v.size(); i++) if (i == 0 || v[i] != v[i - 1]) idx[v[i]] = ++cnt;
    for (int i = 1; i <= n; i++) {
        ans += query(idx[a[i]] + 1) + 1.0;
        update(idx[a[i]]);
    }
    ans /= n;
    printf("%.2f\n", ans);
    return 0;
}
