// Dijkstra's Algorithm
// Time complexity E * log N
// E = number of edges, N = number of nodes

// IMPORTANT NOTE:
//  1e9 has been considered as the infinite distance in both of these algorithm

// using priority queue [ Min - Heap]
vector<int> dijkstra_pq(int src, int n, vector<vector<pair<int, int>>> &adj)
{
    // adjacency list format {{{node, weight}}, {{node,weight},{node,weight}} ........}
    // priority queue format {distance, node}
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    vector<int> dist(n, 1e9);
    dist[src] = 0;
    pq.push({0, src});

    while (!pq.empty()) {
        int distance = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        for (auto it : adj[node]) {
            int adjNode = it.first;
            int edgeWeight = it.second;
            if (distance + edgeWeight < dist[adjNode]) {
                dist[adjNode] = distance + edgeWeight;
                pq.push({distance + edgeWeight, adjNode});
            }
        }
    }
    return dist;
}

//  using set
vector<int> dijkstra_st(int n, int src, vector<vector<pair<int, int>>> &adj)
{a
    set<pair<int, int>> st;  // set format: {distance, node}
    st.insert({0, src});
    vector<int> dist(n, 1e9);
    dist[src] = 0;
    while (!st.empty()) {
        auto it = *(st.begin());
        int distance = it.first;
        int node = it.second;
        st.erase(it);
        for (auto it : adj[node]) {
            int adjNode = it.first;
            int edgeWeight = it.second;
            if (distance + edgeWeight < dist[adjNode]) {
                if (dist[adjNode] != 1e9) {
                    st.erase({dist[adjNode], adjNode});
                }
                dist[adjNode] = distance + edgeWeight;
                st.insert({distance + edgeWeight, adjNode});
            }
        }
    }
    return dist;
}
