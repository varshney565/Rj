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


class comp{
	bool operator(const pair_&a,const pair_ &b){
		return a.w > b.w;
	}
};

void Graph::prism(int src){
	int n = graph.size();
	vector<vector<Edge>> graph2(n);
	priority_queue<pair_,vector<pair_>,comp> pq;
	pq.insert(pair_(src,-1,0,0));
	vector<bool> visited(n,false);
	while(!pq.empty()){
		//get the element with minimum weight
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
	// g2 is MST
}