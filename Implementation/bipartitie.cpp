bool Graph::bipartitie(){
	queue<int> PendingNodes;
	int level = 0;
	vector<int> visited(graph.size(),-1);
	PendingNodes.push(0);
	while(!PendingNodes.empty()){
		int size = PendingNodes.size();
		while(size-->0){
			int front = PendingNodes.front();
			PendingNodes.pop();
			if(visited[front] > -1){
				//cycle is there, check the color
				if(visited[front] == level%2)
					continue;     //even length cycle
				else
					return false; //odd length cycle
			}
			visited[front] = level%2;
			for(auto child : graph[front]){
				if(visited[child.v] == -1){
					PendingNodes.push(child.v);
				}
			}
		}
		level++;
	}
	return true;
}