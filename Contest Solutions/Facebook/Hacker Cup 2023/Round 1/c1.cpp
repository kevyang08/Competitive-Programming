#include <bits/stdc++.h>
using namespace std;

int t, n, q, a, arr[4000001];
string s;
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    freopen("back_in_black_chapter_1_input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    cin >> t;
    for (int bruh = 1; bruh <= t; bruh++) {
        int ans = 0;
        cin >> n >> s >> q;
        for (int i = 1; i <= n; i++) arr[i] = 0;
        while (q--) {
            cin >> a;
            arr[a]++;
        }
        for (int i = n; i > 0; i--) {
            for (int j = 2 * i; j <= n; j += i) arr[j] += arr[i];
            arr[i] += s[i - 1] - '0';
        }
        for (int i = 1; i <= n; i++) {
            if (arr[i]%2 == 0) continue;
            ans++;
            for (int j = i; j <= n; j += i) arr[j]++;
        }
        cout << "Case #" << bruh << ": " << ans << "\n";
    }
    return 0;
}
