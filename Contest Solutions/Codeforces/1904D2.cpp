#include <bits/stdc++.h>
using namespace std;

int t, n, a[200001], b[200001], pos[200001], bit[200001];
bool thing[200001];
void upd1(int i, int v) {
    for (; i > 0; i -= (i & -i)) bit[i] = min(bit[i], v);
}
void upd2(int i, int v) {
    for (; i <= n; i += (i & -i)) bit[i] = min(bit[i], v);
}
int qry1(int i) {
    int res = 0x3f3f3f3f;
    for (; i <= n; i += (i & -i)) res = min(bit[i], res);
    return res;
}
int qry2(int i) {
    int res = 0x3f3f3f3f;
    for (; i > 0; i -= (i & -i)) res = min(bit[i], res);
    return res;
}
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> t;
    while (t--) {
        bool ans = true;
        cin >> n;
        stack<int> st;
        for (int i = 1; i <= n; i++) pos[i] = 0;
        for (int i = 1; i <= n; i++) bit[i] = 0x3f3f3f3f;
        for (int i = 1; i <= n; i++) cin >> a[i];
        for (int i = 1; i <= n; i++) {
            thing[i] = false;
            while (!st.empty() && st.top() <= a[i]) pos[st.top()] = 0, st.pop();
            cin >> b[i];
            // if (a[i] > b[i]) ans = false;
            if (!st.empty() && a[i] != b[i] && pos[b[i]] && qry1(pos[b[i]]) >= b[i]) thing[i] = true;
            st.push(a[i]);
            pos[a[i]] = i;
            upd1(i, b[i]);
        }
        while (!st.empty()) pos[st.top()] = 0, st.pop();
        for (int i = 1; i <= n; i++) bit[i] = 0x3f3f3f3f;
        for (int i = n; i > 0; i--) {
            while (!st.empty() && st.top() <= a[i]) pos[st.top()] = 0, st.pop();
            if (!st.empty() && a[i] != b[i] && pos[b[i]] && qry2(pos[b[i]]) >= b[i]) thing[i] = true;
            st.push(a[i]);
            pos[a[i]] = i;
            upd2(i, b[i]);
            if (!thing[i] && a[i] != b[i]) ans = false;
        }
        cout << (ans ? "YES\n" : "NO\n");
    }
    return 0;
}
 
/*
tips:
- look out for int overflow and array out of bounds
- don't get stuck debugging a wrong solution, take time to think of a new one instead of spammaxg submissions
- make sure stuestion was read correctly
- for certain problems, solve a few cases by hand and try to make observations
- if behind, stop looking at leaderboard and focus on solving
*/