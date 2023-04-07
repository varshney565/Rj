class Solution {
public:
    class Edge{
        public:
            int v,w;
            Edge(int v,int w){
                this->v = v;
                this->w = w;
            }
    };
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<Edge>> graph(n);
        for(auto x : times){
            int u = x[0]-1;
            int v = x[1]-1;
            int w = x[2];
            graph[u].push_back(Edge(v,w));
        }
        
        vector<int> Time(n,INT_MAX);
        Time[k-1] = 0;
        set<pair<int,int>> PendingNodes;
        PendingNodes.insert({0,k-1});
        while(!PendingNodes.empty()){
            auto front = *PendingNodes.begin();
            PendingNodes.erase(front);
            int currentNode = front.second;
            int currentTime = front.first;
            if(Time[currentNode] < currentTime){
                continue;
            }
            for(auto nextNode : graph[currentNode]){
                int v = nextNode.v;
                int w = nextNode.w;
                if(currentTime + w < Time[v]){
                    Time[v] = currentTime+w;
                    PendingNodes.insert({Time[v],v});
                }
            }
        }
        int ans = -1;
        for(int i = 0 ; i < n ; i++){
            ans = max(ans,Time[i]);
        }
        return ans == INT_MAX ? -1 : ans;
    }
};