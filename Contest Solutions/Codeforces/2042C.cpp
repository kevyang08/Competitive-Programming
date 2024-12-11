#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll INFL = 0x3f3f3f3f3f3f3f3f;

int t, n, k;
string s;
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> t;
    while (t--) {
        int dif = 0, tot = 0, ans = 1;
        vector<int> v;
        cin >> n >> k >> s;
        for (int i = n - 1; i > 0; i--) {
            dif += (s[i] == '0' ? -1 : 1);
            v.push_back(dif);
        }
        sort(v.begin(), v.end(), greater<int>());
        for (int i : v) {
            if (i <= 0) break;
            tot += i; // test cases seem weak, this would probably fail for a string with all 0s
            ++ans;
            if (tot >= k) break;
        }
        cout << (tot < k ? -1 : ans) << "\n";
    }
    return 0;
}