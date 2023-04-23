class Solution {
public:
    /**
     * @param grid: a list of lists of integers
     * @return: return an integer, denote the number of distinct islands
     */
    int numberofDistinctIslands(vector<vector<int>> &grid) {
        int n = grid.size();
        int m = grid[0].size();
        set<string> Paths;
        vector<vector<bool>> visited(n,vector<bool>(m,false));
        int dir[][2] = {{1,0},{-1,0},{0,1},{0,-1}};
        function<void(int,int,string&)> dfs = [&](int x,int y,string& s){
            visited[x][y] = true;
            for(int i = 0 ; i < 4 ; i++){
                int newx = x+dir[i][0];
                int newy = y+dir[i][1];
                if(newx >= 0 && newx < n && newy >= 0 && newy < m && !visited[newx][newy] && grid[newx][newy] == 1){
                    s += to_string(i);
                    dfs(newx,newy,s);
                }
            }
            s += "b";
        };
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(!visited[i][j] && grid[i][j] == 1){
                    string s = "";
                    dfs(i,j,s);
                    Paths.insert(s);
                }
            }
        }
        return Paths.size();
    }
};