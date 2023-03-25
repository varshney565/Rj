void Graph::bfs2(int src){
	int n = graph.size();
	vector<int> visited(n,false);
	queue<int> PendingNodes;
	int level = 0;
	PendingNodes.push(src);
	visited[src] = true;
	while(!PendingNodes.empty()){
		cout<<"level : "<<level<<"-->";
		int size = PendingNodes.size();
		while(size-->0){
			int front = PendingNodes.front();
			PendingNodes.pop();
			cout<<front<<" ";
			for(auto child : graph[front]){
				if(!visited[child.v]){
					PendingNodes.push(child.v);
					visited[child.v] = true;
				}
			}
		}
		level++;
		cout<<"\n";
	}

}