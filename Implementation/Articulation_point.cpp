void ap(vector<vector<int>> &graph){
	int n = graph.size();
	vector<int> low(n,-1),in(n,-1);
	vector<bool> visited(n,false),ans(n,false);
	function<void(int,int)> dfs = [&](int src,int par){
		
	};
	for(int i = 0 ; i < n ; i++){
		if(!visited[i]) dfs(i,-1);
	}
}