void Graph::toposort(){
	int n = graph.size();
	vector<bool> visited(n,false);
	vector<int> ans;
	function<void(int)> dfs = [&](int src){
		visited[src] = true;
		for(auto child : graph[src]){
			if(!visited[child.v])
				dfs(child.v);
		}
		ans.push_back(src);
	};

	for(int i = 0 ; i < n ; i++){
		if(!visited[i]){
			dfs(i);
		}
	}
	for(int i = 0 ; i < ans.size() ; i++){
		cout<<ans[i]<<"\n";
	}
}