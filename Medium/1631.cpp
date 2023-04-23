class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        int dir[][2] = {{1,0},{-1,0},{0,-1},{0,1}};
        set<pair<int,int>> PQ;
        PQ.insert({0,0});
        vector<vector<int>> d(n,vector<int>(m,INT_MAX));
        d[0][0] = 0;
        while(!PQ.empty()){
            auto front = *PQ.begin();
            PQ.erase(front);
            int x = front.second/m;
            int y = front.second%m;
            int abd = front.first;
            if(d[x][y] < abd){
                continue;
            }
            if(x == n-1 && y == m-1) return abd;
            for(int i = 0 ; i < 4 ; i++){
                int newx = x+dir[i][0];
                int newy = y+dir[i][1];
                if(newx >= 0 && newx < n && newy >= 0 && newy < m){
                    int diff = abs(heights[x][y]-heights[newx][newy]);
                    diff = max(diff,abd);
                    if(d[newx][newy] > diff){
                        PQ.insert({diff,newx*m+newy});
                        d[newx][newy] = diff;
                    }
                }
            }
        }
        return -1;
    }
};