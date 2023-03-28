class Solution {
public:
    int countPaths(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        const int mod = 1e9+7;
        vector<vector<int>> count(n,vector<int>(m,0));
        int dir[][2] = {{1,0},{-1,0},{0,1},{0,-1}};
        //dfs call here
        function<int(int,int)> dfs = [&](int x,int y){
            count[x][y] = 1;
            for(int i = 0 ; i < 4 ; i++){
                int newx = x+dir[i][0];
                int newy = y+dir[i][1];
                if(newx >= 0 && newx < n && newy >= 0 && newy < m && grid[newx][newy] > grid[x][y]){
                    if(count[newx][newy])
                        count[x][y] = (count[x][y]+count[newx][newy])%mod;
                    else
                        count[x][y] = (count[x][y]+dfs(newx,newy))%mod;
                }
            }
            return count[x][y];
        };
        //actual work done here
        int ans = 0;
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(count[i][j] == 0){
                    dfs(i,j);
                }
                ans = (ans + count[i][j])%mod;
            }
        }
        return ans;
    }
};

