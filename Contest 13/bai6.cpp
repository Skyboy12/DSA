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

bool isSame(Node* root1, Node* root2) {
    if (root1 == NULL && root2 == NULL) return true;
    if (root1 == NULL || root2 == NULL) return false;
    return (root1->data == root2->data) && isSame(root1->left, root2->left) && isSame(root1->right, root2->right);
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n1;
        cin >> n1;
        map<int, Node*> m1;
        Node* root1 = NULL;
        for (int i = 0; i < n1; i++) {
            int u, v;
            char x;
            cin >> u >> v >> x;
            if (m1.find(u) == m1.end()) {
                m1[u] = new Node(u);
                if (root1 == NULL) root1 = m1[u];
            }
            if (m1.find(v) == m1.end()) {
                m1[v] = new Node(v);
            }
            if (x == 'L') m1[u]->left = m1[v];
            else m1[u]->right = m1[v];
        }
        int n2;
        cin >> n2;
        map<int, Node*> m2;
        Node* root2 = NULL;
        for (int i = 0; i < n2; i++) {
            int u, v;
            char x;
            cin >> u >> v >> x;
            if (m2.find(u) == m2.end()) {
                m2[u] = new Node(u);
                if (root2 == NULL) root2 = m2[u];
            }
            if (m2.find(v) == m2.end()) {
                m2[v] = new Node(v);
            }
            if (x == 'L') m2[u]->left = m2[v];
            else m2[u]->right = m2[v];
        }
        cout << (isSame(root1, root2) ? "EQUAL" : "DIFFERENT") << endl;
    }
    return 0;
}