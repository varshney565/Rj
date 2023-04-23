class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& p) {
        vector<vector<int>> graph(n);
        for(int i = 0 ; i < p.size() ; i++){
            graph[p[i][1]].push_back(p[i][0]);
        }
        vector<int> indeg(n,0);
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < graph[i].size() ; j++){
                int child = graph[i][j];
                indeg[child]++;
            }
        }
        queue<int> PendingNodes;
        for(int i = 0 ; i < n ; i++){
            if(indeg[i] == 0){
                PendingNodes.push(i);
            }
        }
        vector<int> ans;
        //bfs
        int lvl = 0;
        while(!PendingNodes.empty()){
            int size = PendingNodes.size();
            while(size--){
                int front = PendingNodes.front();
                PendingNodes.pop();
                ans.push_back(front);
                for(auto child : graph[front]){
                    indeg[child]--;
                    if(indeg[child] == 0) PendingNodes.push(child);
                }
            }
            lvl++;
        }
        if(ans.size() == n) return ans;
        return {};
    }
};