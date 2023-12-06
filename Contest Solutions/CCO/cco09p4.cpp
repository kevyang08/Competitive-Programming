// literally just quicksort

#include <bits/stdc++.h>
using namespace std;

random_device rd;
mt19937 gen(rd());

int n, c[10000];
vector<vector<int>> v;
vector<pair<int, int>> vdx;
vector<int> vb;
void qs(int idx, int x) {
    if (v[idx].size() == 1) {
        cout << "1 " << x << " " << v[idx][0] << "\n";
        return;
    }
    int res;
    if (vb[idx] != -1) {
        cout << "0 " << x << " " << vb[idx] << endl;
        cin >> res;
        if (res > 0) qs(vdx[idx].second, x);
        else qs(vdx[idx].first, x);
        return;
    }
    vdx[idx] = {v.size(), v.size() + 1};
    v.push_back(vector<int>()); v.push_back(vector<int>());
    for (int b : v[idx]) {
        cout << "0 " << x << " " << b << endl;
        cin >> res;
        if (!res) {
            vb[idx] = b;
            cout << "1 " << x << " " << b << "\n";
        }
        else if (res > 0) v[vdx[idx].first].push_back(b);
        else v[vdx[idx].second].push_back(b);
    }
}
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> n;
    v.push_back(vector<int>());
    vdx.resize(16 * n);
    for (int i = 0; i < 16 * n; i++) vb.push_back(-1);
    for (int i = 0; i < n; i++) {
        c[i] = i + 1;
        v[0].push_back(i + 1);
        if (i < 2) continue;
        swap(c[i], c[gen()%i]);
    }
    for (int i = 0; i < n; i++) qs(0, c[i]);
    return 0;
}
