#include <bits/stdc++.h>
using namespace std;

struct Node {
    int v, h = 0, bf = 0, sz = 1, c = 1;
    Node *l = nullptr, *r = nullptr;
    Node(int val): v{val} {}
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
        while (node -> l) node = node -> l;
        return node;
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
    int getSize() {
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
};
int n, m, k, dt = 0, cnt = 0;
char op;
Tree tree;
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin >> n >> m;
    while (n--) {
        cin >> op >> k;
        if (op == 'I') {
            if (k < m) continue;
            tree.insert(k - dt);
            cnt++;
        }
        else if (op == 'A') dt += k;
        else if (op == 'S') {
            dt -= k;
            tree.remove(m - dt - 1);
        }
        else cout << (k > tree.getSize() ? -1 : tree.find(k) + dt) << "\n";
    }
    cout << cnt - tree.getSize() << "\n";
    return 0;
}
