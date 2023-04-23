class Solution {
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> graph(n);
        for(int i = 0 ; i < connections.size() ; i++){
            int u = connections[i][0];
            int v = connections[i][1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        
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
        return ans;
    }
};