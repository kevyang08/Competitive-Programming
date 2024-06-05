#include <bits/stdc++.h>
using namespace std;

int t, n, a[200001], b[200001];
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> t;
    while (t--) {
        cin >> n;
        int l = 1, r = n;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            if (a[i] != -1) b[i] = a[i];
            else b[i] = -1;
        }
        while (l <= n && a[l] == -1) l++;
        while (r > l && a[r] == -1) r--;
        if (l > n) {
            for (int i = 1; i <= n; i++) cout << 1 + i%2 << (i == n ? "\n" : " ");
            continue;
        }
        for (int i = l - 1; i > 0; i--) b[i] = (i%2 == l%2 ? b[l] : b[i + 1] * 2);
        for (int i = r + 1; i <= n; i++) b[i] = (i%2 == r%2 ? b[r] : b[i - 1] * 2);
        int p = l;
        bool ans = true;
        for (int i = l + 1; i <= r; i++) {
            if (a[i] == -1) continue;
            if (a[i] == a[p]) {
                if ((i - p)%2) {
                    ans = false;
                    break;
                }
                for (int j = p + 1; j < i; j++) b[j] = (j%2 == p%2 ? b[p] : b[j - 1] * 2);
            }
            else {
                int mn = min(a[i], a[p]), mx = max(a[i], a[p]), cnta = 0, cntb = 0;
                stack<int> st;
                while (mx != mn) {
                    st.push(mx & 1);
                    mx >>= 1;
                    cnta++;
                    if (__builtin_clz(mx) > __builtin_clz(mn)) {
                        mn >>= 1;
                        cntb++;
                    }
                }
                if (i - p < cnta + cntb || (i - p - cnta - cntb)%2) {
                    ans = false;
                    break;
                }
                if (min(a[i], a[p]) == a[p]) {
                    for (int j = 1; j <= cntb; j++) b[p + j] = b[p + j - 1]/2;
                    for (int j = cntb + 1; j <= cnta + cntb; j++) {
                        b[p + j] = (b[p + j - 1] << 1 | st.top());
                        st.pop();
                    }
                    for (int j = i - 1; j > p + cnta + cntb; j--) b[j] = (i%2 == j%2 ? b[i] : b[j + 1] * 2);
                }
                else {
                    for (int j = 1; j <= cntb; j++) b[i - j] = b[i - j + 1]/2;
                    for (int j = cntb + 1; j <= cnta + cntb; j++) {
                        b[i - j] = (b[i - j + 1] << 1 | st.top());
                        st.pop();
                    }
                    for (int j = p + 1; j < i - cnta - cntb; j++) b[j] = (p%2 == j%2 ? b[p] : b[j - 1] * 2);
                }
            }
            p = i;
        }
        if (!ans) cout << "-1\n";
        else for (int i = 1; i <= n; i++) cout << b[i] << (i == n ? "\n" : " ");
    }
    return 0;
}

/*
tips:
- look out for int overflow and array out of bounds
- don't get stuck debugging a wrong solution, take time to think of a new one instead of spamming submissions
- make sure stuestion was read correctly
- for certain problems, solve a few cases by hand and try to make observations
- if behind, stop looking at leaderboard and focus on solving
*/
