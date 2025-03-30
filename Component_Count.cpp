#include <iostream>
#include <vector>
using namespace std;

void dfs(int node, vector<vector<int>> &adj, vector<bool> &visited)
{
    visited[node] = true;
    for (int neighbor : adj[node])
    {
        if (!visited[neighbor])
        {
            dfs(neighbor, adj, visited);
        }
    }
}

int main()
{
    int v, e;
    cin >> v >> e;

    vector<vector<int>> adj(v + 1);
    vector<bool> visited(v + 1, false);

    for (int i = 0; i < e; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    int components = 0;

    for (int i = 1; i <= v; i++)
    {
        if (!visited[i])
        {
            dfs(i, adj, visited);
            components++;
        }
    }

    cout << components << endl;
    return 0;
}