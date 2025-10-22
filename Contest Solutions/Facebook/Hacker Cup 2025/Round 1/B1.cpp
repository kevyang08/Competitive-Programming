#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll INFL = 0x3f3f3f3f3f3f3f3f;

int t, n, a, b;
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    freopen("final_product_chapter_1_input.txt", "r", stdin);
    freopen("final_product_chapter_1_output.txt", "w", stdout);
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        cout << "Case #" << tt << ": ";
        cin >> n >> a >> b;
        for (int i = 1; i < 2 * n; i++) cout << 1 << " ";
        cout << b << "\n";
    }
    return 0;
}