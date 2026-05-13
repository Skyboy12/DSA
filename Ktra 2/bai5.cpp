#include <bits/stdc++.h>

using namespace std;

struct Node
{
    int value;
    Node *left, *right;
    Node(int val) : value(val), left(nullptr), right(nullptr) {}
};

Node *insert(Node *root, int value)
{
    if (!root)
        return new Node(value);
    if (value < root->value)
        root->left = insert(root->left, value);
    else
        root->right = insert(root->right, value);
    return root;
}

void leafNodes(Node *root, vector<int> &leaves)
{
    if (!root)
        return;
    if (!root->left && !root->right)
        leaves.push_back(root->value);
    leafNodes(root->left, leaves);
    leafNodes(root->right, leaves);
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        Node *root = nullptr;
        for (int i = 0; i < n; i++)
        {
            int value;
            cin >> value;
            root = insert(root, value);
        }
        vector<int> leaves;
        leafNodes(root, leaves);
        sort(leaves.begin(), leaves.end());
        for (int leaf : leaves)
        {
            cout << leaf << " ";
        }
        cout << endl;
    }
}
