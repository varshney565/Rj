class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        //multi source bfs
        int n = grid.size();
        int m = grid[0].size();
        //the level i of that queue will represent current status of rotting oranges at ith minute
        queue<int> PendingNodes;
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(grid[i][j] == 2){
                    PendingNodes.push(i*m+j);
                }
            }
        }
        int dir[][2] = {{1,0},{-1,0},{0,1},{0,-1}};
        int minute = 0;
        
        while(!PendingNodes.empty()){
            int size = PendingNodes.size();
            while(size-->0){
                int front = PendingNodes.front();
                PendingNodes.pop();
                int x = front/m;
                int y = front%m;
                for(int i = 0 ; i < 4 ; i++){
                    int newx = x+dir[i][0];
                    int newy = y+dir[i][1];
                    if(newx >= 0 && newx < n && newy >= 0 && newy < m && grid[newx][newy] == 1){
                        PendingNodes.push(newx*m+newy);
                        grid[newx][newy] = 2;
                    }
                }
            }
            if(PendingNodes.size())
                minute++;
        }
        
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(grid[i][j] == 1){
                    return -1;
                }
            }
        }
        return minute;
    }
};