class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<vector<int>> graph(n);
        for(int i = 0 ; i < dislikes.size() ; i++){
            int a = dislikes[i][0]-1;
            int b = dislikes[i][1]-1;
            graph[a].push_back(b);
            graph[b].push_back(a);
        }
        vector<int> visited(n,-1);
        bool ans = true;
        auto bfs = [&](int src){
            queue<int> PendingNodes;
            PendingNodes.push(src);
            int level = 0;
            while(!PendingNodes.empty()){
                int size = PendingNodes.size();
                while(size-->0){
                    int front = PendingNodes.front();
                    PendingNodes.pop();
                    if(visited[front] > -1){
                        if(visited[front] == level%2) continue; //even
                        return false; //odd
                    }
                    visited[front] = level%2;
                    for(auto child : graph[front]){
                        if(visited[child] == -1){
                            PendingNodes.push(child);
                        }
                    }
                }
                level++;
            }
            return true; //no cycle or even length cycle
        };
        for(int i = 0 ; i < n ; i++){
            if(visited[i] == -1){
                ans = ans && bfs(i);
            }
        }
        return ans;
    }
};