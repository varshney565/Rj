class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n = matrix.size(),m = matrix[0].size();
        vector<vector<int>> dep(n,vector<int>(m,0));
        int dir[][2] = {{1,0},{-1,0},{0,-1},{0,1}};
        queue<int> PendingNodes;
        //filling the dependencies
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                for(int k = 0 ; k < 4 ; k++){
                    int newi = i+dir[k][0];
                    int newj = j+dir[k][1];
                    if(newi >= 0 && newi < n && newj < m && newj >= 0 && matrix[newi][newj] < matrix[i][j])
                        dep[i][j]++;
                }
                if(dep[i][j] == 0){
                    PendingNodes.push(i*m+j);
                }
            }
        }
        //bfs
        int lvl = 1;
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
                    if(newx >= 0 && newx < n && newy >= 0 && newy < m && matrix[newx][newy] > matrix[x][y]){
                        if(--dep[newx][newy] == 0){
                            PendingNodes.push(newx*m+newy);
                        }
                    }
                }
            }
            if(PendingNodes.size() > 0)
                lvl++;
        }
        return lvl;
    }
};