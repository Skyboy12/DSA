#include <bits/stdc++.h>

using namespace std;

int n, m, q;
vector<int> parent_node, sz;

void make_set(int n)
{
    parent_node.resize(n + 1);
    sz.resize(n + 1, 1);
    for (int i = 1; i <= n; i++)
    {
        parent_node[i] = i;
    }
}

int find_set(int v)
{
    if (v == parent_node[v])
        return v;
    return parent_node[v] = find_set(parent_node[v]);
}

void union_sets(int a, int b)
{
    a = find_set(a);
    b = find_set(b);
    if (a != b)
    {
        if (sz[a] < sz[b])
            swap(a, b);
        parent_node[b] = a;
        sz[a] += sz[b];
    }
}

int main()
{
    cin >> n >> m >> q;
    vector<pair<int, int>> edge(m + 1);
    for (int i = 1; i <= m; i++)
    {
        cin >> edge[i].first >> edge[i].second;
    }

    vector<pair<int, int>> queries(q);
    vector<bool> removed(m + 1, false);
    for (int i = 0; i < q; i++)
    {
        cin >> queries[i].first >> queries[i].second;
        removed[queries[i].first] = true;
    }

    make_set(n);
    for (int i = 1; i <= m; i++)
    {
        if (!removed[i])
        {
            union_sets(edge[i].first, edge[i].second);
        }
    }

    vector<int> ans(q);
    for (int i = q - 1; i >= 0; i--)
    {
        ans[i] = sz[find_set(queries[i].second)];
        int e = queries[i].first;
        union_sets(edge[e].first, edge[e].second);
    }

    for (int i = 0; i < q; i++)
    {
        cout << ans[i] << "\n";
    }

    return 0;
}
