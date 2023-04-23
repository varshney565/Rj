class Dsu{
    public:
    vector<int> p;
    vector<int> s;
    Dsu(int n){
        p.resize(n);
        iota(p.begin(),p.end(),0);
        s.resize(n,1);
    }
    
    int get(int n){
        if(p[n] == n) return n;
        return p[n] = get(p[n]);
    }
    
    bool unite(int a,int b){
        int p1 = get(a);
        int p2 = get(b);
        if(p1 == p2){
            return false;
        }
        p[p1] = p2;
        s[p2] += s[p1];
        return true;
    }
};
class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int ans = 0;
        Dsu d(n*m);
        int dir[][2] = {{1,0},{-1,0},{0,1},{0,-1}};
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(grid[i][j] == 0) continue;
                for(int k = 0 ; k < 4 ; k++){
                    int newi = i+dir[k][0];
                    int newj = j+dir[k][1];
                    if(newi >= 0 && newi < n && newj >= 0 && newj < m && grid[newi][newj] == 1){
                        d.unite(newi*m+newj,i*m+j);
                    }
                }
                ans = max(ans,d.s[d.get(i*m+j)]);
            }
        }
        return ans;
    }
};