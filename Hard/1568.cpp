class Solution {
public:
    int minDays(vector<vector<int>>& grid) {
        /**
         * total three cases are there : 
         * a ) if already more than one component are there in the graph ; ans = 0;
         * b ) there is one articulation point in the graph ; ans = 1;
         * c ) not following the above two rules ; ans = 2;
        */
        int n = grid.size();
        int m = grid[0].size();
        int components = 0;
        int nO1 = 0;
        int dir[][2] = {{0,1},{0,-1},{1,0},{-1,0}};
        vector<int> in(n*m,-1),low(n*m,-1);
        vector<bool> visited(n*m,false);
        bool isFoundAP = false;
        int time = 0;
        function<void(int,int)> dfs = [&](int u,int p){
            visited[u] = true;
            in[u] = low[u] = time++;
            int x = u/m,y = u%m;
            int children = 0;
            for(int i = 0 ; i < 4 ; i++){
                int newx = x+dir[i][0];
                int newy = y+dir[i][1];
                int child = newx*m+newy;
                if(newx >= 0 && newx < n && newy >= 0 && newy < m && grid[newx][newy] == 1){
                    if(child == p) continue;
                    if(visited[child]){
                        low[u] = min(low[u],in[child]);
                    }else{
                        dfs(child,u);
                        children++;
                        low[u] = min(low[u],low[child]);
                        if(in[u] <= low[child] && p != -1)
                            isFoundAP = true;
                    }
                }
            }
            if(p == -1 && children > 1) isFoundAP = true;
        };
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(grid[i][j] == 1){
                    if(!visited[i*m+j]){
                        dfs(i*m+j,-1);
                        components++;
                    }
                    nO1++;
                }
            }
        }
        if(components > 1) return 0;
        if(isFoundAP)
            return 1;
        if(nO1 == 0) return 0;
        if(nO1 == 1) return 1;
        return 2;
    }
};