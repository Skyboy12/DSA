#include <bits/stdc++.h>

using namespace std;

struct Node
{
    int data;
    Node *left, *right;
    Node(int x)
    {
        data = x;
        left = right = NULL;
    }
};

void spiralOrder(Node *root)
{
    if (root == NULL)
        return;
    stack<Node *> s1, s2;
    s1.push(root);
    while (!s1.empty() || !s2.empty())
    {
        while (!s1.empty())
        {
            Node *temp = s1.top();
            s1.pop();
            cout << temp->data << " ";
            if (temp->right)
                s2.push(temp->right);
            if (temp->left)
                s2.push(temp->left);
        }
        while (!s2.empty())
        {
            Node *temp = s2.top();
            s2.pop();
            cout << temp->data << " ";
            if (temp->left)
                s1.push(temp->left);
            if (temp->right)
                s1.push(temp->right);
        }
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        map<int, Node *> m;
        Node *root = NULL;
        for (int i = 0; i < n; i++)
        {
            int u, v;
            char x;
            cin >> u >> v >> x;
            if (m.find(u) == m.end())
            {
                m[u] = new Node(u);
                if (root == NULL)
                    root = m[u];
            }
            if (m.find(v) == m.end())
            {
                m[v] = new Node(v);
            }
            if (x == 'L')
                m[u]->left = m[v];
            else
                m[u]->right = m[v];
        }
        spiralOrder(root);
        cout << endl;
    }
    return 0;
}