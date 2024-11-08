// traversal for graph
// dfs

void dfs(int node, vector<int> &vis, vector<vector<int>> &adj)
{
    vis[node] = 1;
    for (int val : adj[node]) {
        if (!vis[val]) {
            dfs(val, vis, adj);
        }
    }
}

// bfs

void bfs(int src, vector<int> &vis, vector<vector<int>> &adj)
{
    queue<int> q;
    vis[src] = 1;
    q.push(src);
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        for (int val : adj[node]) {
            if (!vis[val]) {
                q.push(val);
                vis[val] = 1;
            }
        }
    }
}