void Graph::toposort_khan(){
	int n = graph.size();
	vector<bool> visited(n,false);
	vector<int> indeg(n,0);
	queue<int> PendingNodes;
	vector<int> ans;
	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < graph[i].size() ; j++){
			auto child = graph[i][j];
			indeg[child.v]++;
			if(indeg[child.v] == 0){
				PendingNodes.push(child.v);
			}
		}
	}
	//apply bfs
	int level = 0;
	while(!PendingNodes.empty()){
		int size = PendingNodes.size();
		while(size-->0){
			int front = PendingNodes.front();
			PendingNodes.pop();
			ans.push_back(front);
			for(auto child : graph[front]){
				indeg[child.v]--;
				if(indeg[child.v] == 0)
					PendingNodes.push(child.v);
			}
		}
		level++;
	}
	if(ans.size() != n){
		cout<<"Cycle is present\n";return;
	}
	for(int i = 0 ; i < n ; i++){
		cout<<ans[i]<<" ";
	}
	cout<<"\n";
}