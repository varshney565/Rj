void kosaraju(vector<vector<Edge>> &graph){

	//a)   find the nodes in the sorted order of their finish time.
	int n = graph.size();
	vector<int> outTimeNodes;
	vector<bool> visited(n,false);
	function<void(int)> dfs1 = [&](int src){
		visited[src] = true;
		for(auto child : graph[src]){
			if(!visited[child.v]){
				dfs1(child.v);
			}
		}
		outTimeNodes.push_back(src);
	};
	for(int v = 0 ; v < n ; v++){
		if(!visited[v])
			dfs1(v);
	}

	//b) 	reverse the graph.
	vector<vector<Edge>> G(n);
	for(int u = 0 ; u < n ; u++){
		for(int j = 0 ; j < graph[u].size() ; j++){
			int v = graph[i].v;
			int w = graph[i].w;
			G[v].push_back(Edge(u,w));
		}
	}


	//c)	find the scc, simply apply dfs starting from the nodes that are going to finish last in the dfs call.
	function<void(int)> dfs = [&](int src){
		visited[src] = true;
		cout<<src<<" ";
		for(auto child : G[src]){
			if(!visited[child.v])
				dfs(child.v);
		}
	};
	visited.assign(n,false);
	for(int i = outTimeNodes.size()-1 ; i >= 0 ; i--){
		if(!visited[outTimeNodes[i]]){
			dfs(outTimeNodes[i]);
			cout<<"\n";
		}
	}
}