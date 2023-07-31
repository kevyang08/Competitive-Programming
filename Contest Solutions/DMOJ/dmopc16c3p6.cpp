#include <bits/stdc++.h>
using namespace std;

struct Node {
    int sum, pr, su;
    Node *l, *r;
    Node(int v = 0) {
        sum = pr = su = v;
        l = nullptr;
        r = nullptr;
    }
    Node(Node *ptr) {
        sum = ptr -> sum;
        pr = ptr -> pr;
        su = ptr -> su;
        l = r = nullptr;
    }
    ~Node() {
        if (l) delete l;
        if (r) delete r;
    }
};
int n, q, x, y, c = 0, arr[100001];
char op;
Node *root[500001];
void pushUp(Node* node) {
    node -> sum = node -> l -> sum + node -> r -> sum;
    node -> pr = max(node -> l -> pr, node -> l -> sum + node -> r -> pr);
    node -> su = max(node -> r -> su, node -> r -> sum + node -> l -> su);
}
void build(Node* node, int l, int r) {
    if (l == r) {
        node -> pr = node -> su = node -> sum = arr[l];
        return;
    }
    int m = (l + r)/2;
    build(node -> l = new Node(), l, m);
    build(node -> r = new Node(), m + 1, r);
    pushUp(node);
}
void upgrade(Node* prev, Node* curr, int l, int r, int idx, int v) {
    if (l == r) {
        curr -> pr = curr -> su = curr -> sum = v;
        return;
    }
    int m = (l + r)/2;
    if (idx <= m) {
        upgrade(prev -> l, curr -> l = new Node(), l, m, idx, v);
        curr -> r = prev -> r;
    }
    else {
        upgrade(prev -> r, curr -> r = new Node(), m + 1, r, idx, v);
        curr -> l = prev -> l;
    }
    pushUp(curr);
}
Node* query(Node* node, int l, int r, int ql, int qr) {
    if (l > qr || r < ql) return nullptr;
    if (ql <= l && r <= qr) return new Node(node);
    int m = (l + r)/2;
    Node* res = new Node();
    res -> l = query(node -> l, l, m, ql, qr);
    res -> r = query(node -> r, m + 1, r, ql, qr);
    if (res -> l == nullptr) {
        res -> pr = res -> r -> pr;
        res -> su = res -> r -> su;
        res -> sum = res -> r -> sum;
    }
    else if (res -> r == nullptr) {
        res -> pr = res -> l -> pr;
        res -> su = res -> l -> su;
        res -> sum = res -> l -> sum;
    }
    else pushUp(res);
    return res;
}
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> arr[i];
    root[0] = new Node();
    build(root[0], 1, n);
    cin >> q;
    while (q--) {
        cin >> op;
        if (op == 'U') {
            cin >> x >> y;
            root[++c] = new Node();
            upgrade(root[c - 1], root[c], 1, n, x, y);
        }
        else if (op == 'G') {
            cin >> x;
            root[++c] = root[x];
        }
        else {
            cin >> x >> y;
            auto res = query(root[c], 1, n, x, y);
            cout << (op == 'P' ? res -> pr : res -> su) << "\n";
            delete res;
        }
    }
    return 0;
}
