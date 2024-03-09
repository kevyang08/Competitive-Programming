#include <bits/stdc++.h>
using namespace std;

int n, l, a, b, id[300001], out[300001];
bool used[300001];
int find(int i) {
    return (id[i] == i ? i : (id[i] = find(id[i])));
}
void thing(int u, int v) {
    out[find(u)] = 0;
    if ((u = find(u)) != (v = find(v))) {
        id[v] = u;
        out[u] = out[v];
    }
    out[v] = 0;
}
bool join(int a, int b) {
    if (!used[a]) {
        if (!id[a]) id[a] = a;
        if (!used[b]) {
            if (!id[b]) id[b] = b;
            id[find(b)] = find(a);
            out[find(a)] = b;
        }
        else thing(a, b);
        used[a] = true;
    }
    else if (!used[b]) {
        if (!id[b]) id[b] = b;
        thing(b, a);
        used[b] = true;
    }
    else if (out[find(a)]) {
        used[out[find(a)]] = true;
        thing(a, b);
    }
    else if (out[find(b)]) {
        used[out[find(b)]] = true;
        thing(b, a);
    }
    else return false;
    return true;
}
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> n >> l;
    for (int i = 1; i <= n; i++) {
        cin >> a >> b;
        if (join(a, b)) cout << "LADICA\n";
        else cout << "SMECE\n";
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
