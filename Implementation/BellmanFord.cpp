void Graph::BellManFord(vector<vector<int>> Edges,int src){
	int n = graph.size();
	vector<int> d(n,INT_MAX);
    d[src] = 0;
    for(int i = 1 ; i <= n ; i++){
        vector<int> x = d;
        bool update = false;
        for(int j = 0 ; j < Edges.size() ; j++){
            int u = Edges[j][0],v = Edges[j][1],w = Edges[j][2];
            if(d[u] < INT_MAX){
                x[v] = min(x[v],d[u]+w);
                update = true;
            }
        }
        if(!update)
            break;
        swap(x,d);
    }
	//now check for cycle
	if(update){
		cout<<"cycle is there with neagitive weight.\n";
	}
	//no cycle with neagitive weight, we have the shortest distance from source to all other vertexs in the distance array.
}