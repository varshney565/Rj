int Graph::gcc(){
    int n = graph.size();
    vector<bool> visited(n,false);
    function<void(int)> dfs = [&](int src){
        visited[src] = true;
        for(auto child : graph[src]){
            if(!visited[child.v]){
                dfs(child.v);
            }
        }
    };
    int count = 0;
    for(int i = 0 ; i < n ; i++){
        if(!visited[i]){
            count++;
            dfs(i);
        }
    }
    return count;
}