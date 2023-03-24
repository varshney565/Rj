class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        //direction array
        int dir[][2] = {{1,0},{-1,0},{0,1},{0,-1}};
        
        //making dfs call
        function<void(int,int)> dfs = [&](int x,int y){
            board[x][y] = 'T';
            for(int i = 0 ; i < 4 ; i++){
                int newx = x+dir[i][0];
                int newy = y+dir[i][1];
                if(newx >= 0 && newx < n && newy >= 0 & newy < m && board[newx][newy] == 'O'){
                    dfs(newx,newy);
                }
            }
        };    
        
        //logic
        for(int i = 0 ; i < n ; i++){
            if(board[i][0] == 'O') dfs(i,0);
            if(board[i][m-1] == 'O') dfs(i,m-1);
        }
        for(int j = 0 ; j < m ; j++){
            if(board[0][j] == 'O') dfs(0,j);
            if(board[n-1][j] == 'O') dfs(n-1,j);
        }
        for(int i = 0; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(board[i][j] == 'T'){
                    board[i][j] = 'O';
                }else if(board[i][j] == 'O'){
                    board[i][j] = 'X';
                }
            }
        }
    }
};