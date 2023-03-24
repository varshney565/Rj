class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int dir[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
        vector<vector<bool>> visited(n,vector<bool>(m,false));
        function<int(int,int)> dfs = [&](int x,int y){
            visited[x][y] = true;
            int cnt = 0;
            for(int i = 0 ; i < 4 ; i++){
                int newx = x+dir[i][0];
                int newy = y+dir[i][1];
                if(newx >= 0 && newx < n && newy >= 0 && newy < m){
                    if(!visited[newx][newy]  && grid[newx][newy] == 1)
                        cnt += dfs(newx,newy);
                    else if(!visited[newx][newy] && grid[newx][newy] == 0)
                        cnt++;                        
                }else{
                    cnt++;
                }
            }
            return cnt;
        };
        int cnt = 0;
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(grid[i][j] == 1){
                    return dfs(i,j);
                }
            }
        }
        return cnt;
    }
};

/**
 *or simply run two loops because there is only one island and check whether that perticuler land is associated 
 * with a cell will 0 value or not, if yes increase the value of count by 1.
 * 
 * at the end return ans.
 * */
