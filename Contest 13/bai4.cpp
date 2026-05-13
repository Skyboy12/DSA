#include <bits/stdc++.h>

using namespace std;

struct Node {
    int data;
    Node *left, *right;
    Node(int x) {
        data = x;
        left = right = NULL;
    }
};

bool isFull(Node *root) {
    if (root == NULL) return true;
    if (root->left == NULL && root->right == NULL) return true;
    if (root->left && root->right) {
        return isFull(root->left) && isFull(root->right);
    }
    return false;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        map<int, Node*> m;
        Node* root = NULL;
        for (int i = 0; i < n; i++) {
            int u, v;
            char x;
            cin >> u >> v >> x;
            if (m.find(u) == m.end()) {
                m[u] = new Node(u);
                if (root == NULL) root = m[u];
            }
            if (m.find(v) == m.end()) {
                m[v] = new Node(v);
            }
            if (x == 'L') m[u]->left = m[v];
            else m[u]->right = m[v];
        }
        cout << (isFull(root) ? "YES" : "NO") << endl;
    }
    return 0;
}