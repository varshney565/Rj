class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        //make a visited array
        vector<vector<bool>> visited(n,vector<bool>(m,false));
        //direction array
        int dir[][2] = {{1,0},{-1,0},{0,1},{0,-1}};
        //dfs function
        function<int(int,int)> dfs = [&](int x,int y){
            visited[x][y] = true;
            int cnt = 1;
            for(int i = 0 ; i < 4 ; i++){
                int newx = x+dir[i][0];
                int newy = y+dir[i][1];
                if(newx >= 0 && newx < n && newy >= 0 && newy < m && !visited[newx][newy] && grid[newx][newy] == 1)
                    cnt += dfs(newx,newy);
            }
            return cnt;
        };
        
        //actual thing will happen here
        int cnt = 0;
        int max_ = 0;
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(grid[i][j] == 1 && !visited[i][j]){
                    cnt++;
                    max_ = max(max_,dfs(i,j));
                }
            }
        }
        return max_;
    }
};