class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        int dir[][2] = {{1,0},{-1,0},{0,1},{0,-1}};
        
        queue<int> PendingNodes;
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(mat[i][j] == 0){
                    PendingNodes.push(i*m+j);
                }else if(mat[i][j] == 1){
                    mat[i][j] = -1;
                }
            }
        }
        int level = 0;
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
                    if(newx >= 0 && newx < n && newy >= 0 && newy < m && mat[newx][newy] == -1){
                        PendingNodes.push(newx*m+newy);
                        mat[newx][newy] = level+1;
                    }
                }
            }
            level++;
        }
        return mat;
    }
};