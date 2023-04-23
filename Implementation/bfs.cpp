void Graph::bfs(int src){
	int n = graph.size();
	vector<int> visited(n,false);
	queue<int> PendingNodes;
	int level = 0;
	PendingNodes.push(src);
	while(!PendingNodes.empty()){
		cout<<"level : "<<level<<"-->";
		int size = PendingNodes.size();
		while(size-->0){
			int front = PendingNodes.front();
			PendingNodes.pop();
			if(visited[front])
				continue;//cycle is there
			cout<<front<<" ";
			visited[front] = true;
			for(auto child : graph[front]){
				if(!visited[child.v])
					PendingNodes.push(child.v);
			}
		}
		level++;
		cout<<"\n";
	}

}