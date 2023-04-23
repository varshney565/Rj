class Dsu{
    public:
    vector<int> p,s,cinf;
    Dsu(int n,vector<int> &initial){
        p.resize(n);
        iota(p.begin(),p.end(),0);
        s.resize(n,1);
        cinf.resize(n,0);
        for(auto x : initial){
            cinf[x] = 1;
        }
    }
    
    int get(int n){
        if(p[n] == n)
            return n;
        return p[n] = get(p[n]);
    }
    
    bool unite(int a,int b){
        int p1 = get(a);
        int p2 = get(b);
        if(p1 == p2){
            return false;
        }
        if(cinf[p1]){
            p[p2] = p1;
            s[p1] += s[p2];
            cinf[p1] += cinf[p2];
        }else{
            p[p1] = p2;
            s[p2] += s[p1];
            cinf[p2] += cinf[p1];
        }
        return true;
    }
};
class Solution {
public:
    int minMalwareSpread(vector<vector<int>>& graph, vector<int>& initial) {
        int n = graph.size();
        Dsu d(n,initial);
        for(int i = 0 ; i < n ; i++){
            for(int j = i + 1 ; j < n ; j++){
                if(graph[i][j]){
                    d.unite(i,j);
                }
            }
        }
        int ans = -1;
        int cnt = 0;
        sort(initial.begin(),initial.end());
        for(auto i : initial){
            if(d.p[i] == i && d.cinf[i] == 1 && d.s[i] > cnt){
                ans = i;
                cnt = d.s[i];
            }
        }
        return ans == -1 ? initial[0] : ans;
    }
};