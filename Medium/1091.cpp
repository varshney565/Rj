class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int dir[][2] = {{1,0},{-1,0},{0,1},{0,-1},{1,1},{1,-1},{-1,1},{-1,-1}};
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> visited(n,vector<bool>(m,false));
        if(grid[0][0] == 1 || grid[n-1][m-1] == 1)
            return -1;
        queue<int> PendingNodes;
        PendingNodes.push(0);
        visited[0][0] = true;
        int level = 1;
        while(!PendingNodes.empty()){
            int size = PendingNodes.size();
            while(size-->0){
                int front = PendingNodes.front();
                PendingNodes.pop();
                int x = front/m;
                int y = front%m;
                if(x == n-1 && y == m-1) return level;
                for(int i = 0 ; i < 8 ; i++){
                    int newx = x+dir[i][0];
                    int newy = y+dir[i][1];
                    if(newx >= 0 && newx < n && newy >= 0 && newy < m && !visited[newx][newy] && grid[newx][newy] == 0){
                        PendingNodes.push(newx*m+newy);
                        visited[newx][newy] = true;
                    }
                }
            }
            level++;
        }
        return -1;
    }
};