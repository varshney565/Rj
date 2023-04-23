class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& p) {
        vector<vector<int>> graph(n);
        for(int i = 0 ; i < p.size() ; i++){
            graph[p[i][0]].push_back(p[i][1]);
        }
        vector<int> visited(n,0);
        vector<int> ans;
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
        for(int i = 0 ; i < n ; i++){
            if(!visited[i]){
                bool res = dfs(i);
                if(!res)
                    return {};
            }
        }
        return ans;
    }
};
