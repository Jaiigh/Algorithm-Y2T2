#include <iostream>
#include <vector>
using namespace std;

bool dfs(int node, int parent, vector<vector<int>> &adj, vector<bool> &visited)
{
    visited[node] = true;

    for (int neighbor : adj[node])
    {
        if (!visited[neighbor])
        {
            if (dfs(neighbor, node, adj, visited))
                return true;
        }
        else if (neighbor != parent)
        {
            return true;
        }
    }

    return false;
}

bool hasCycle(int n, vector<vector<int>> &adj)
{
    vector<bool> visited(n, false);

    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            if (dfs(i, -1, adj, visited))
                return true;
        }
    }
    return false;
}

int main()
{
    int T;
    cin >> T;

    while (T--)
    {
        int N, E;
        cin >> N >> E;

        vector<vector<int>> adj(N); // 0-based indexing

        for (int i = 0; i < E; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u); // undirected graph
        }

        if (hasCycle(N, adj))
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
    }

    return 0;
}