void ap(vector<vector<int>> &graph){
	int n = graph.size();
	vector<int> low(n,-1),in(n,-1);
	vector<bool> visited(n,false),ans(n,false);
	int time = 0;
	function<void(int,int)> dfs = [&](int u,int p){
		visited[u] = true;
		in[u] = low[u] = time++;
		int children = 0;
		for(auto child : graph[u]){
			if(child == p) continue;
			if(visited[child]){
				low[u] = min(low[u],in[child]);
			}else{
				dfs(child,u);
				children++;
				low[u] = min(low[u],low[child]);
				if(low[child] >= in[u]){
					ans[u] = true;
				}
			}
		}
		if(p == -1 && children > 1) ans[u] = true;
	};
	for(int i = 0 ; i < n ; i++){
		if(!visited[i]) dfs(i,-1);
	}
	//print all the articulation points
}