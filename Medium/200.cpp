
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        //make a direction array
        int dir[][2] = {{1,0},{0,1},{-1,0},{0,-1}};
        //dimentions of the grid
        int n = grid.size();
        int m = grid[0].size();
        //make a visited grid
        vector<vector<bool>> visited(n,vector<bool>(m,false));
        //dfs function
        function<void(int,int)> dfs = [&](int i,int j){
            //mark as visited
            visited[i][j] = true;
            //make the dfs call on all the unvisited neibhours
            for(int x = 0 ; x < 4 ; x++){
                int newi = i+dir[x][0];
                int newj = j+dir[x][1];
                
                if(newi >= 0 && newi < n && newj >= 0 && newj < m && !visited[newi][newj] && grid[newi][newj] == '1'){
                    dfs(newi,newj);
                }
            }
        };
        //making the dfs call on all the unvisited cells where grid[i][j] = 1
        int cnt = 0;
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(grid[i][j] == '1' && !visited[i][j]){
                    cnt++;
                    dfs(i,j);
                }
            }
        }
        return cnt;
    }
};