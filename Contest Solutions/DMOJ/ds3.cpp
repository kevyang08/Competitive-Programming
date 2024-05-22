#include <bits/stdc++.h>
using namespace std;

// for some reason the java version tle'd

struct Node {
    int mn, gcd, cnt;
    Node(int mn, int gcd, int cnt) : mn(mn), gcd(gcd), cnt(cnt) {}
};

vector<Node*> tree;
int n, m;

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

void update(int x, int v) {
    x += n - 1;
    tree[x] -> mn = tree[x] -> gcd = v;
    for (int i = x / 2; i > 0; i /= 2) {
        tree[i] -> mn = min(tree[2 * i] -> mn, tree[2 * i + 1] -> mn);
        tree[i] -> gcd = gcd(tree[2 * i] -> gcd, tree[2 * i + 1] -> gcd);
        tree[i] -> cnt = 0;
        if (tree[i] -> gcd == tree[2 * i] -> gcd) tree[i] -> cnt += tree[2 * i] -> cnt;
        if (tree[i] -> gcd == tree[2 * i + 1] -> gcd) tree[i] -> cnt += tree[2 * i + 1] -> cnt;
    }
}

int mQuery(int l, int r) {
    int mn = INT_MAX;
    for (l += n, r += n; l < r; l /= 2, r /= 2) {
        if (l % 2 == 1) mn = min(mn, tree[l++] -> mn);
        if (r % 2 == 1) mn = min(mn, tree[--r] -> mn);
    }
    return mn;
}

int gQuery(int l, int r) {
    int res = tree[l + n] -> mn;
    for (l += n, r += n; l < r; l /= 2, r /= 2) {
        if (l % 2 == 1) res = gcd(res, tree[l++] -> gcd);
        if (r % 2 == 1) res = gcd(res, tree[--r] -> gcd);
    }
    return res;
}

int qQuery(int l, int r) {
    int res = gQuery(l, r), cnt = 0;
    for (l += n, r += n; l < r; l /= 2, r /= 2) {
        if (l % 2 == 1 && res == tree[l++] -> gcd) cnt += tree[l - 1] -> cnt;
        if (r % 2 == 1 && res == tree[--r] -> gcd) cnt += tree[r] -> cnt;
    }
    return cnt;
}

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> n >> m;
    tree.resize(2 * n);

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        tree[i + n] = new Node(x, x, 1);
    }

    for (int i = n - 1; i > 0; i--) {
        tree[i] = new Node(min(tree[2 * i] -> mn, tree[2 * i + 1] -> mn), gcd(tree[2 * i] -> gcd, tree[2 * i + 1] -> gcd), 0);
        if (tree[i] -> gcd == tree[2 * i] -> gcd) tree[i] -> cnt += tree[2 * i] -> cnt;
        if (tree[i] -> gcd == tree[2 * i + 1] -> gcd) tree[i] -> cnt += tree[2 * i + 1] -> cnt;
    }

    for (int k = 0; k < m; k++) {
        char op;
        cin >> op;
        if (op == 'C') {
            int x, v;
            cin >> x >> v;
            update(x, v);
        } else if (op == 'M') {
            int l, r;
            cin >> l >> r;
            cout << mQuery(l - 1, r) << "\n";
        } else if (op == 'G') {
            int l, r;
            cin >> l >> r;
            cout << gQuery(l - 1, r) << "\n";
        } else {
            int l, r;
            cin >> l >> r;
            cout << qQuery(l - 1, r) << "\n";
        }
    }

    return 0;
}
