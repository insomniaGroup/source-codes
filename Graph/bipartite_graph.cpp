bool bipartite_dfs(int src, bool col, vector<int> &vis, vector<vector<int>> &adj)
{
    vis[src] = col;
    for (auto adjNode : adj[src]) {
        if (vis[adjNode] == -1) {
            if (bipartite_dfs(adjNode, !col, vis, adj) == false) return false;
        } else if (vis[adjNode] == col) {
            return false;
        }
    }
    return true;
}

bool bipartite_bfs(int src, vector<int> &vis, vector<vector<int>> &adj)
{
    queue<pair<int, int>> q;
    q.push({src, 0});
    vis[src] = 0;
    while (!q.empty()) {
        int node = q.front().first;
        bool color = q.front().second;
        q.pop();
        for (auto adjNode : adj[node]) {
            if (vis[adjNode] == -1) {
                vis[adjNode] = !color;
                q.push({adjNode, !color});
            } else if (vis[adjNode] == color) {
                return false;
            }
        }
    }
    return true;
}