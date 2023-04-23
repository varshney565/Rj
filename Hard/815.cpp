class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        if(source == target) return 0;
        map<int,vector<int>> mapping;
        int n = routes.size();
        for(int i = 0 ; i < routes.size() ; i++){
            for(int j = 0 ; j < routes[i].size() ; j++){
                mapping[routes[i][j]].push_back(i);
            }
        }
        vector<bool> visited(n,false);
        queue<int> PendingStations;
        for(auto x : mapping[source]){
            for(int i = 0 ; i < routes[x].size() ; i++){
                PendingStations.push(routes[x][i]);
            }
            visited[x] = true;
        }
        mapping[source].clear();
        int level = 1;
        while(!PendingStations.empty()){
            int size = PendingStations.size();
            while(size-->0){
                int Stop = PendingStations.front();
                PendingStations.pop();
                if(Stop == target){
                    return level;
                }
                for(auto x : mapping[Stop]){
                    if(visited[x]) continue;
                    for(int i = 0 ; i < routes[x].size() ; i++){
                        PendingStations.push(routes[x][i]);
                    }
                    visited[x] = true;
                }
                mapping[Stop].clear();
            }
            level++;
        }
        return -1;
    }
};