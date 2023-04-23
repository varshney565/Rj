class pair_{
public:
	int src;
	int v;
	int w;
	int wsf;

	pair_(int src,int v,int w,int wsf = 0){
		this->src = src;
		this->par = v;
		this->w = w;
		this->wsf = wsf;
	}
};

/**
 * time complexity of dijkstra algorithem in the worst case scenerio will be O(VlogE+ElogE)
 * which will be equavilant to (V+E)logV
 * */

class comp{
	bool operator(const pair_&a,const pair_ &b){
		return a.wsf > b.wsf;
	}
};

void Graph::dijkstra1(int src){
	int n = graph.size();
	vector<vector<Edge>> graph2(n);
	priority_queue<pair_,vector<pair_>,comp> pq;
	pq.insert(pair_(src,-1,0,0));
	vector<bool> visited(n,false);
	while(!pq.empty()){
		//get the element with minimum wsf
		auto t = pq.top();
		pq.pop();
		//check if that vertex is visited or not if yes continue
		if(visited[t.src]) continue;
		visited[t.src] = true;
		if(t.par == -1)
			g2.addEdge(t.src,t.par,t.w);
		//go to all the unvisited childrens of that vertex and insert them in priority queue.
		for(auto child : graph[t.src]){
			if(!visited[child.v]){
				pq.push(pair_(child.v,t.src,child.w,t.wsf+child.w));
			}
		}
	}
	//g2 is the graph with minimum distance from source to destination
}

void Graph::dijkstra2(int src){
	int n = graph.size();
	priority_queue<pair_,vector<pair_>,comp> pq;
	pq.insert(pair_(src,-1,0,0));
	vector<bool> visited(n,false);
	vector<int> dis(n,INT_MAX),par(n,-1);
	dis[src] = 0;
	while(!pq.empty()){
		//pop the element with minimum wsf
		auto t = pq.top();
		pq.pop();
		if(visited[t.src]) continue;
		//go to all the unvisited neibhours of src and relex them.
		for(auto child : graph[t.src]){
			if(dis[t.wsf+child.w < dis[child.v]]){
				dis[child.v] = t.wsf+child.w;
				pq.push(pair_(child.v,t.src,child.w,child.w+t.wsf));
			}
		}
	}
	//now i have the distance array which has the minimum distance from source to all the vertices.
}