class dsu{
public:
    vector<int> p;
    vector<int> s;
    dsu(int n){
        p.resize(n);
        iota(p.begin(),p.end(),0);
        s.resize(n,1);
    }

    int get(int n){
        if(p[n] == n) return n;
        return p[n] = get(p[n]);
    }

    bool unite(int a,int b){
        int p1 = get(a),p2 = get(b);
        if(p1 == p2) return false;
        p[p1] = p2;
        s[p2] += s[p1];
        return true;
    }
};

class Solution {
public:
    int minCostToSupplyWater(int n, vector<int>& wells, vector<vector<int>>& pipes) {
        for(int i = 0 ; i < wells.size() ; i++){
            pipes.push_back({i+1,n+1,wells[i]});
        }
        sort(pipes.begin(),pipes.end(),[&](const vector<int>&a,const vector<int>&b){
            return a[2] < b[2];
        });
        n = pipes.size();
        dsu d(n);
        int ans = 0;
        for(int i = 0 ; i < n ; i++){
            if(d.unite(pipes[i][0]-1,pipes[i][1]-1)) ans += pipes[i][2];
        }
        return ans;
    }
};