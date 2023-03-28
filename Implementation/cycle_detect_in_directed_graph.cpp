
bool Graph::cycleDetect() {
    int n = graph.size();
    vector<int> visited(n,0);
    vector<int> ans;
    //logic to detect cycle in the graph
    function<bool(int)> dfs = [&](int src){
        visited[src] = 1;
        for(auto child : graph[src]){
            if(!visited[child]){
                bool res = dfs(child);
                if(!res)
                    return false;
            }else if(visited[child] == 1){
                return false;
            }
        }
        ans.push_back(src);
        visited[src] = 2;
        return true;
    };
    //apply dfs on all the parts of graph
    for(int i = 0 ; i < n ; i++){
        if(!visited[i]){
            bool res = dfs(i);
            if(!res)
                return false;
        }
    }
    return true;
}