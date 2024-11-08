// It returns true if a cycle is detected in an undirected graph

bool bfs_cycle_detect(int src, vector<int> &vis, vector<vector<int>> &adj)
{
    queue<pair<int, int>> q;
    q.push({src, -1});
    vis[src] = 1;
    while (!q.empty()) {
        int node = q.front().first;
        int parent = q.front().second;
        q.pop();
        for (int adjNode : adj[node]) {
            if (!vis[adjNode]) {
                q.push({adjNode, node});
                vis[adjNode] = 1;
            } else if (adjNode != parent) {
                return true;
            }
        }
    }
    return false;
}

bool dfs_cycle_detect(int src, int parent, vector<int> &vis, vector<vector<int>> &adj)
{
    vis[src] = 1;
    for (auto adjNode : adj[src]) {
        if (!vis[adjNode]) {
            if (dfs_cycle_detect(adjNode, src, vis, adj)) {
                reutrn true;
            }
        } else if (adjNode != parent) {
            return true;
        }
    }
    return false;
}
