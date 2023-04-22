void fw(vector<vector<int>> graph){
	//graph is passed as adj matrix with weights if there is not
	//Edge btw any two vertex the distance will be INT_MAX
	int n = graph.size();
	for(int k = 0 ; k < n ; k++){
		for(int i = 0 ; i < n ; i++){
			for(int j = 0 ; j < n ; j++){
				if(d[i][k] < INT_MAX && d[k][j] < INT_MAX && d[i][j] > d[i][k] + d[k][j])
					d[i][j] = d[i][k]+d[k][j];
			}
		}
	}
	//now i have all pair shortest paths in the graph 2D array.
}