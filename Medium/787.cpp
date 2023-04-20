class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& Edges, int src, int dst, int k) {
        k++;
        vector<int> d(n,INT_MAX);
        d[src] = 0;
        for(int i = 1 ; i <= k ; i++){
            vector<int> x = d;
            bool update = false;
            for(int j = 0 ; j < Edges.size() ; j++){
                int u = Edges[j][0],v = Edges[j][1],w = Edges[j][2];
                if(d[u] < INT_MAX){
                    x[v] = min(x[v],d[u]+w);
                    update = true;
                }
            }
            if(!update)
                break;
            swap(x,d);
        }
        return d[dst]==INT_MAX?-1:d[dst];
    }
};