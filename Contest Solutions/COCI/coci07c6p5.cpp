#include <bits/stdc++.h>
using namespace std;

/*
y - x is minor diagonal
y + x is major diagonal
*/

typedef long long ll;

int n, k, x, y, cmaj, cmin;
string s;
map<int, set<int>> smaj, smin;
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> n >> k >> s;
    cin >> x >> y;
    cmaj = y + x, cmin = y - x;
    for (int i = 1; i < n; i++) {
        cin >> x >> y;
        smaj[y + x].insert(y - x);
        smin[y - x].insert(y + x);
    }
    auto del = [&](auto cmaj, auto cmin) {
        smaj[cmaj].erase(cmin);
        smin[cmin].erase(cmaj);
    };
    for (int i = 0; i < k; i++) {
        switch (s[i]) {
            case 'A':
                if (smin[cmin].upper_bound(cmaj) != smin[cmin].end()) {
                    del(cmaj, cmin);
                    cmaj = *smin[cmin].upper_bound(cmaj);
                }
                break;
            case 'B':
                if (smaj[cmaj].lower_bound(cmin) != smaj[cmaj].begin()) {
                    del(cmaj, cmin);
                    cmin = *(--smaj[cmaj].lower_bound(cmin));
                }
                break;
            case 'C':
                if (smaj[cmaj].upper_bound(cmin) != smaj[cmaj].end()) {
                    del(cmaj, cmin);
                    cmin = *smaj[cmaj].upper_bound(cmin);
                }
                break;
            case 'D':
                if (smin[cmin].lower_bound(cmaj) != smin[cmin].begin()) {
                    del(cmaj, cmin);
                    cmaj = *(--smin[cmin].lower_bound(cmaj));
                }
                break;
            default:
                break;
        }
    }
    cout << (cmaj - cmin)/2 << " " << (cmaj + cmin)/2 << "\n";
    return 0;
}