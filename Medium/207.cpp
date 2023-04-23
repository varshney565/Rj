class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& p) {
        vector<vector<int>> graph(n);
        for(int i = 0 ; i < p.size() ; i++){
            graph[p[i][0]].push_back(p[i][1]);
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
        //bfs
        int lvl = 0;
        int cnt = 0;
        while(!PendingNodes.empty()){
            int size = PendingNodes.size();
            while(size--){
                int front = PendingNodes.front();
                PendingNodes.pop();
                cnt++;
                for(auto child : graph[front]){
                    indeg[child]--;
                    if(indeg[child] == 0) PendingNodes.push(child);
                }
            }
            lvl++;
        }
        return cnt == n;
    }
};