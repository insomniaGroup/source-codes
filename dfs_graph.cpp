// dfs for graph

void dfs(int node, vector<int> adj[], vector<int> &ans,int vis[]){
	vis[node] = 1;
	ans.push_back(node);
	for(int val : adj[node]){
		if(!vis[val]) dfs(val,adj,ans,vis);
	}
}
