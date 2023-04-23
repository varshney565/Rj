class Solution {
public:
    class _pair{
        public : 
        int x;
        int y;
        int d;
        string path;
        _pair(int x,int y,int d,string s = ""){
            this->x = x;
            this->y = y;
            this->d = d;
            this->path = s;
        }
    };

    class comp{
        public : 
        bool operator()(const _pair& a,const _pair& b) const {
            if(a.d != b.d) return a.d < b.d;
            return a.path < b.path;
        }
    };

    string findShortestWay(vector<vector<int>>& maze, vector<int>& ball, vector<int>& hole) {
        int n = maze.size();
        int m = maze[0].size();
        int dir[][2] = {{1,0},{0,-1},{0,1},{-1,0}};
        string path = "dlru";
        set<_pair,comp> PS;
        PS.insert(_pair(ball[0],ball[1],0));
        
        vector<vector<int>> visited(n,vector<int>(m,false));
        while(!PS.empty()){
            auto front = *PS.begin();
            PS.erase(front);
            if(visited[front.x][front.y]) continue;

            if(front.x == hole[0] && front.y == hole[1]){
                return front.path;
            }
            
            visited[front.x][front.y] = true;
            for(int i = 0 ; i < 4 ; i++){
                int x = front.x;
                int y = front.y;
                int dx = dir[i][0];
                int dy = dir[i][1];
                while(0 <= x+dx && x+dx < n && 0 <= y+dy && y+dy < m && maze[x+dx][y+dy] == 0){
                    x += dx;
                    y += dy;
                    if(x == hole[0] && y == hole[1]) break;
                }
                if(!visited[x][y]){
                    PS.insert(_pair(x,y,front.d+abs(front.x-x)+abs(front.y-y),front.path+path[i]));
                }
            }
        }
        return "impossible";
    }
};