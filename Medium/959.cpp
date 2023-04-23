class Dsu{
    public:
        vector<int> p;
        Dsu(int n){
            p.resize(n);
            iota(p.begin(),p.end(),0);
        }
    
        int get(int n){
            if(p[n] == n) return n;
            return p[n] = get(p[n]);
        }
    
        bool unite(int a,int b){
            int p1 = get(a);
            int p2 = get(b);
            if(p1 == p2) return false;
            p[p1] = p2;
            return true;
        }
};
class Solution {
public:
    int regionsBySlashes(vector<string>& grid) {
        int n = grid.size();
        int m = n+1;
        Dsu d(m*m);
        for(int i = 0 ; i < m ; i++){
            //unite 0 and everything
            d.unite(0,i);
            d.unite(0,i*m);
            d.unite(0,i*m+m-1);
            d.unite(0,(m-1)*m+i);
        }
        int ans = 1;
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < n ; j++){
                if(grid[i][j] == '/'){
                    int i1 = i;
                    int i2 = i+1;
                    int j1 = j+1;
                    int j2 = j;
                    int val1 = i1*m+j1;
                    int val2 = i2*m+j2;
                    if(!d.unite(val1,val2)){
                        ans++;
                    }
                }else if(grid[i][j] == '\\'){
                    int i1 = i;
                    int i2 = i+1;
                    int j1 = j;
                    int j2 = j+1;
                    int val1 = i1*m+j1;
                    int val2 = i2*m+j2;
                    if(!d.unite(val1,val2)){
                        ans++;
                    }                    
                }
            }
        }
        return ans;
    }
};