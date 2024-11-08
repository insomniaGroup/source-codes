

class DisjointSet
{
   public:
    vector<int> parent, size;

    DisjointSet(int n)
    {
        parent.resize(n + 1);
        size.resize(n + 1, 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }

    int find(int node)
    {
        if (node == parent[node]) {
            return node;
        }
        return parent[node] = find(parent[node]);
    }

    void unite(int u, int v)
    {
        int root_u = find(u);
        int root_v = find(v);
        if (root_u == root_v) return;

        if (size[root_u] < size[root_v]) {
            parent[root_u] = root_v;
            size[root_v] += size[root_u];
        } else {
            parent[root_v] = root_u;
            size[root_u] += size[root_v];
        }
    }

    int component_size(int node)
    {
        return size[find(node)];
    }
};