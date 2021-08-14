#include <iostream>
#include <vector>
using namespace std;

void dfs(int j, vector<vector<int>> &adj, vector<bool> &vis)
{
    if (vis[j])
        return;
    vis[j] = true;
    for (auto ch : adj[j])
    {
        dfs(ch, adj, vis);
    }
}

int main()
{
    int n, e, u, v;
    cin >> n >> e;

    vector<bool> vis(n + 1);
    vector<vector<int>> adj(n + 1);

    for (int i = 1; i <= e; i++)
    {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            dfs(i, adj, vis);
            cnt++;
        }
    }
    cout << cnt << endl;
    return 0;
}
