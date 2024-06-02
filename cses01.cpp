#include <bits/stdc++.h>
#define ll int long long
using namespace std;

void dfs(vector<vector<char>> &adj, vector<vector<ll>> &vis, ll i, ll j, ll n, ll m)
{
    if (i < 0 || i >= n || j < 0 || j >= m || adj[i][j] == '#' || vis[i][j] == 1)
        return;

    vis[i][j] = 1;
    adj[i][j] = '#';
    dfs(adj, vis, i + 1, j, n, m);
    dfs(adj, vis, i - 1, j, n, m);
    dfs(adj, vis, i, j + 1, n, m);
    dfs(adj, vis, i, j - 1, n, m);
}

int main()
{
    ll n, m;
    cin >> n >> m;
    vector<vector<char>> adj(n, vector<char>(m, 0));

    // Reading the grid
    for (ll i = 0; i < n; i++)
    {
        for (ll j = 0; j < m; j++)
        {
            cin >> adj[i][j];
        }
    }
    vector<vector<ll>> vis(n, vector<ll>(m, 0));
    ll cnt = 0;

    for (ll i = 0; i < n; i++)
    {
        for (ll j = 0; j < m; j++)
        {
            if (adj[i][j] == '.' && vis[i][j] == 0)
            {
                cnt++;

                dfs(adj, vis, i, j, n, m);
            }
        }
    }

    cout << cnt << endl;
    return 0;
}
