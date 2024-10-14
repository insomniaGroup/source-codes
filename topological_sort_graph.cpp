// For a topoSort graph must be Directed Acylic Graph [DAG]

// dfs code
// take out the elements from the stack and the resulting array is one of the toposort sequence

void topo_sort_dfs(int src, vector<int> &vis, vector<vector<int>> &adj, stack<int> &st)
{
    vis[src] = 1;
    for (auto adjNode : adj[src]) {
        if (!vis[adjNode]) {
            topo_sort_dfs(adjNode, vis, adj, st);
        }
    }
    st.push(src);
}

// bfs code [khan's algorithm]

void topo_sort_bfs(int n, vector<vector<int>> &adj, vector<int> &topoSort)
{
    vector<int> indegree(n, 0);
    for (int i = 0; i < n; i++) {
        for (auto adjNode : adj[i]) {
            indegree[adjNode]++;
        }
    }

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
