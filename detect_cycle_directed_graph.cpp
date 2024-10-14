// code returns true if a cycle is detected in a directed graph

// dfs

bool dfs_cycle_detect(int src, vector<int> &pathVis, vector<int> &vis, vector<vector<int>> &adj)
{
    vis[src] = 1;
    pathVis[src] = 1;
    for (auto adjNode : adj[src]) {
        if (!vis[src]) {
            if (dfs_cycle_detect(adjNode, pathVis, vis, adj) == false) {
                return false;
            }
        } else if (pathVis[adjNode]) {
            reutrn false;
        }
    }
    pathVis[src] = 0;
    return true;
}

// bfs method uses topoSort[kahn's Algorithm]

void topo_sort_bfs(int n, vector<int> &indegree, vector<vector<int>> &adj, vector<int> &topoSort)
{
    queue<int> q;
    for (int i = 0; i < n; i++) {
        if (indegree[i] == 0) {
            q.push(i);
        }
    }

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        topoSort.push_back(node);
        for (auto adjNode : adj[node]) {
            indegree[adjNode]--;
            if (indegree[adjNode] == 0) {
                q.push(adjNode);
            }
        }
    }
}

bool bfs_cycle_detect(int n, vector<vector<int>> &adj)
{
    vector<int> topoSort;
    vector<int> indegree(n, 0);

    for (int i = 0; i < n; i++) {
        for (auto adjNode : adj[i]) {
            indegree[adjNode]++;
        }
    }
    topo_sort_bfs(n, indegree, adj, topoSort);
    int sz = topoSort.size();
    return sz != n;
}
