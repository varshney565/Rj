#include<bits/stdc++.h>
class dsu{
    public:
        vector<int> p;

        dsu(int n){
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
    vector<int> numIslands2(int n, int m, vector<Point> &operators) {
        dsu d(m*n);
        int dir[][2] = {{1,0},{0,-1},{-1,0},{0,1}};
        vector<vector<int>> mat(n,vector<int>(m,0));
        vector<int> ans;
        int val = 0;
        for(int i = 0 ; i < operators.size() ; i++){
            int x = operators[i].x;
            int y = operators[i].y;
            if(mat[x][y] == 1) {
                ans.push_back(val);
                continue;
            }
            val++;
            mat[x][y] = 1;
            for(int k = 0 ; k < 4 ; k++){
                int newx = x+dir[k][0];
                int newy = y+dir[k][1];
                if(newx >= 0 && newx < n && newy >= 0 && newy < m && mat[newx][newy] == 1){
                    if(d.unite(newx*m+newy,x*m+y))
                        val--;
                }
            }
            ans.push_back(val);
        }
        return ans;
    }
};