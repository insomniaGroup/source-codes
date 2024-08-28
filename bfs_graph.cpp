//bfs for graph

void bfsOfGraph(int src, vector<int> adj[]) {
	queue<int> q;
	vis[src] = 1;
	q.push(src);
	while(!q.empty()){
		int node = q.front();
		q.pop();
		for(int val : adj[node]){
			if(!vis[val]){
				q.push(val);
				vis[val] = 1;
			}
		}
	}
}
