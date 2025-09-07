#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll INFL = 0x3f3f3f3f3f3f3f3f;
const int M = 998244353;
// const int M = 1e9 + 7;

int n;
char a[200001], b[200001];
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> n >> a >> b;
    for (int i = 0; i < n; i++) if (a[i] > b[i]) swap(a[i], b[i]);
    ll tmpa = 0, ans = 0;
    for (int i = 0; i < n; i++) tmpa = (tmpa * 10 + a[i] - '0')%M;
    for (int i = 0; i < n; i++) ans = (ans * 10 + tmpa * (b[i] - '0'))%M;
    cout << ans << "\n";
    return 0;
}