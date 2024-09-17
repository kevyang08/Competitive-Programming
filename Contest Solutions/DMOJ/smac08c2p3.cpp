#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n, a;
void solve(vector<int>& v, int n) {
    if (n == 1) return;
    vector<int> l(v.begin(), v.begin() + v.size()/2), r(v.begin() + v.size()/2, v.end());
    int tmp = 1;
    for (int i : l) tmp *= i;
    cout << tmp << " " << n/tmp << endl;
    cin >> a;
    if (a == tmp) solve(l, tmp);
    else solve(r, n/tmp);
}
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> n;
    int tmp = n;
    vector<int> v;
    for (int i = 2; i * i <= n; i++) {
        while (tmp%i == 0) {
            v.push_back(i);
            tmp /= i;
        }
    }
    if (tmp) v.push_back(tmp);
    solve(v, n);
    return 0;
}