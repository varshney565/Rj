//lintcode 663
class Solution {
public:
    void wallsAndGates(vector<vector<int>> &rooms) {
        const int INF = 2147483647;
        int n = rooms.size();
        int m = rooms[0].size();
        queue<int> PendingNodes;
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(rooms[i][j] == 0){
                    PendingNodes.push(i*m+j);
                }
            }
        }
        int dir[][2] = {{1,0},{-1,0},{0,1},{0,-1}};
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
                    if(newx >= 0 && newx < n && newy >= 0 && newy < m && rooms[newx][newy] == INF){
                        PendingNodes.push(newx*m+newy);
                        rooms[newx][newy] = level+1;
                    }
                }
            }
            level++;
        }
    }
};