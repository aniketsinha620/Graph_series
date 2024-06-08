#include <bits/stdc++.h>
using namespace std;

class DisjointSet
{
    vector<int> rank, parent;

public:
    DisjointSet(int n)
    {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);

        for (int i = 0; i <= n; i++)
            parent[i] = i;
    }

    int findParent(int node)
    {
        if (node == parent[node])
            return node;

        return parent[node] = findParent(parent[node]);
    }

    void unionSet(int u, int v)
    {
        int ulp_u = findParent(u);
        int ulp_v = findParent(v);

        if (ulp_u == ulp_v)
            return;

        if (rank[ulp_u] < rank[ulp_v])
            parent[ulp_u] = ulp_v;
        else if (rank[ulp_u] > rank[ulp_v])
            parent[ulp_v] = ulp_u;
        else
        {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }
};

int main()
{
    DisjointSet ds(7);

    ds.unionSet(1, 2);
    ds.unionSet(2, 3);
    ds.unionSet(4, 5);
    ds.unionSet(6, 7);
    ds.unionSet(5, 6);
    ds.unionSet(3, 7);

    cout << "Parent of 1: " << ds.findParent(1) << endl;
    cout << "Parent of 2: " << ds.findParent(2) << endl;
    cout << "Parent of 3: " << ds.findParent(3) << endl;
    cout << "Parent of 4: " << ds.findParent(4) << endl;
    cout << "Parent of 5: " << ds.findParent(5) << endl;
    cout << "Parent of 6: " << ds.findParent(6) << endl;
    cout << "Parent of 7: " << ds.findParent(7) << endl;

    return 0;
}
