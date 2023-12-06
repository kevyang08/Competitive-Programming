#include <bits/stdc++.h>
using namespace std;

int n, arr[5001], freq, c = 1;
vector<int> v;
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> n;
    arr[1] = 1;
    v.push_back(1);
    for (int i = 2; i <= n; i++) {
        cout << "? " << 1 << " " << i << endl;
        cin >> freq;
        if (freq > c) arr[i] = ++c;
        else {
            int l = 0, r = c - 1, idx = 0;
            while (l <= r) {
                int m = (l + r)/2;
                cout << "? " << v[m] << " " << i << endl;
                cin >> freq;
                if (freq <= c - m) {
                    idx = m;
                    l = m + 1;
                }
                else r = m - 1;
            }
            arr[i] = arr[v[idx]];
            v.erase(v.begin() + idx);
        }
        v.push_back(i);
    }
    cout << "!";
    for (int i = 1; i <= n; i++) cout << " " << arr[i];
    cout << "\n";
    return 0;
}
