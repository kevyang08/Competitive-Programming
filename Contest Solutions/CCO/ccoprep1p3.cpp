#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll INFL = 0x3f3f3f3f3f3f3f3f;

struct Node {
    int v, h = 0, bf = 0, sz = 1, c = 1;
    Node *l = nullptr, *r = nullptr;
    Node(int val): v{val} {}
    Node(Node *cp) {
        v = cp -> v;
        c = cp -> c;
        if (cp -> l) l = new Node(cp -> l);
    }
    // ~Node() {
    //     if (l) delete l;
    //     if (r) delete r;
    // }
};
class Tree {
    Node *root = nullptr;
public:
    void insert(int val) {
        root = insert(root, val);
    }
    Node* insert(Node *node, int val) {
        if (node == nullptr) return new Node(val);
        else if (val == node -> v) node -> c++;
        else if (val > node -> v) node -> r = insert(node -> r, val);
        else node -> l = insert(node -> l, val);
        update(node);
        return balance(node);
    }
    void remove(int val) {
        root = remove(root, val);
    }
    Node* remove(Node *node, int val) {
        if (node == nullptr) return nullptr;
        if (val < node -> v) node -> l = remove(node -> l, val);
        else {
            node -> r = remove(node -> r, val);
            if (node -> r) {
                Node *mn = getMin(node -> r);
                node -> v = mn -> v;
                node -> c = mn -> c;
                node -> l = nullptr;
                node -> r = remove(node -> r, node -> v);
            }
            else return nullptr;
        }
        update(node);
        return balance(node);
    }
    Node* getMin(Node *node) {
        Node *temp = new Node(node);
        while (temp -> l) temp = temp -> l;
        return temp;
    }
    void update(Node *node) {
        int lh = -1, rh = -1;
        node -> sz = node -> c;
        if (node -> l) {
            lh = node -> l -> h;
            node -> sz += node -> l -> sz;
        }
        if (node -> r) {
            rh = node -> r -> h;
            node -> sz += node -> r -> sz;
        }
        node -> h = 1 + max(lh, rh);
        node -> bf = rh - lh;
    }
    Node* balance(Node *node) {
        if (node -> bf == -2) {
            if (node -> l -> bf > 0) node -> l = leftRotate(node -> l);
            node = rightRotate(node);
        }
        else if (node -> bf == 2) {
            if (node -> r -> bf < 0) node -> r = rightRotate(node -> r);
            node = leftRotate(node);
        }
        return node;
    }
    Node* leftRotate(Node *node) {
        Node *right = node -> r;
        node -> r = right -> l;
        right -> l = node;
        update(node);
        update(right);
        return right;
    }
    Node* rightRotate(Node *node) {
        Node *left = node -> l;
        node -> l = left -> r;
        left -> r = node;
        update(node);
        update(left);
        return left;
    }
    int size() {
        return root == nullptr ? 0 : root -> sz;
    }
    int find(int val) {
        return find(root, val, 0);
    }
    int find(Node *node, int val, int r) {
        if (r + (node -> r ? node -> r -> sz : 0) >= val) return find(node -> r, val, r);
        else if (r + (node -> r ? node -> r -> sz : 0) + node -> c < val) return find(node -> l, val, r + (node -> r ? node -> r -> sz : 0) + node -> c);
        return node -> v;
    }
    void moveAll(Tree *o) {
        moveAll(root, o);
    }
    void moveAll(Node *node, Tree *o) {
        if (node == nullptr) return;
        o -> insert(node -> v);
        moveAll(node -> l, o);
        moveAll(node -> r, o);
    }
};

int n, m, a, q, x, y, id[200005], mp[200005], idx[200005];
char op;
Tree st[200005];
int find(int x) {
    return (id[x] == x ? x : id[x] = find(id[x]));
}
void join(int x, int y) {
    if (st[x = find(x)].size() < st[y = find(y)].size()) {
        id[x] = y;
        st[x].moveAll(&st[y]);
    }
    else {
        id[y] = x;
        st[y].moveAll(&st[x]);
    }
}
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) id[i] = i, st[i].insert(i);
    for (int i = 1; i <= n; i++) {
        cin >> a;
        mp[i] = a, idx[a] = i;
    }
    while (m--) {
        cin >> x >> y;
        x = mp[x], y = mp[y];
        if (find(x) != find(y)) join(x, y);
    }
    cin >> q;
    while (q--) {
        cin >> op >> x >> y;
        x = find(mp[x]);
        if (op == 'B') {
            y = mp[y];
            if (find(x) != find(y)) join(x, y);
        }
        else {
            if (st[x].size() < y) cout << "-1\n";
            else cout << idx[st[x].find(st[x].size() - y + 1)] << "\n";
        }
    }
    return 0;
}