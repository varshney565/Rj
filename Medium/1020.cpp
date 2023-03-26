class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        queue<int> PendingNodes;
        vector<vector<bool>> visited(n,vector<bool>(m,false));
        for(int i = 0 ; i < n ; i++){
            if(grid[i][0] == 1 && !visited[i][0]) {
                PendingNodes.push(i*m);
                visited[i][0] = true;
            }
            if(grid[i][m-1] == 1 && !visited[i][m-1]) {
                PendingNodes.push(i*m+m-1);
                visited[i][m-1] = true;
            }
        }
        for(int i = 0 ; i < m ; i++){
            if(grid[0][i] == 1 && !visited[0][i]) {
                PendingNodes.push(i);
                visited[0][i] = true;
            }
            if(grid[n-1][i] == 1 && !visited[n-1][i]) {
                PendingNodes.push(n*m-m+i);
                visited[n-1][i] = true;
            }
        }
        int dir[][2] = {{1,0},{-1,0},{0,-1},{0,1}};
        int cnt = 0;
        while(!PendingNodes.empty()){
            int size = PendingNodes.size();
            while(size-->0){
                int front = PendingNodes.front();
                PendingNodes.pop();
                cnt++;
                int x = front/m;
                int y = front%m;
                for(int i = 0 ; i < 4 ; i++){
                    int newx = x+dir[i][0];
                    int newy = y+dir[i][1];
                    if(newx >= 0 && newx < n && newy >= 0 && newy < m && grid[newx][newy] == 1 && !visited[newx][newy]){
                        PendingNodes.push(newx*m+newy);
                        visited[newx][newy] = true;
                    }
                }
            }
        }
    
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(grid[i][j] == 1)
                    cnt--;
            }
        }
        return abs(cnt);
    }
};