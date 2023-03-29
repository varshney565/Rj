class Solution {
public:
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int n = grid1.size();
        int m = grid1[0].size();
        int dir[][2] = {{1,0},{-1,0},{0,1},{0,-1}};
        function<bool(int,int)> dfs = [&](int i,int j){
            grid2[i][j] = 0;
            bool ans = true;
            if(grid1[i][j] == 0){
                ans = false;
            }
            for(int x = 0 ; x < 4 ; x++){
                int newi = i+dir[x][0];
                int newj = j+dir[x][1];
                if(newi >= 0 && newi < n && newj >= 0 && newj < m && grid2[newi][newj] == 1){
                    ans = dfs(newi,newj) && ans;
                }
            }
            return ans;
        };
        
        int cnt = 0;
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(grid2[i][j] == 1){
                    
                    bool ans = dfs(i,j);
                    if(ans)
                        cnt++;
                }
            }
        }
        return cnt;
    }
};
