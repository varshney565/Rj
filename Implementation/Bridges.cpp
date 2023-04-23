void Bridges(vector<vector<int>> &graph){
    int n = graph.size();
    vector<int> low(n,-1),in(n,-1);
    vector<int> visited(n,false);
    vector<vector<int>> ans;
    int time = 0;
    function<void(int,int)> dfs = [&](int u,int p){
        visited[u] = true;
        low[u] = in[u] = time++;
        for(auto child : graph[u]){
            if(child == p) continue;
            if(!visited[child]){
                dfs(child,u);
                low[u] = min(low[u],low[child]);
                if(in[u] < low[child]){
                    vector<int> Edge = {u,child};
                    ans.push_back(Edge);
                }
            }else{
                low[u] = min(low[u],in[child]);
            }
        }
    };
    dfs(0,-1);
    //ans will have all the edges that are contributing to bridges in the graph
}