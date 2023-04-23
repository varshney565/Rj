class Dsu{
    public : 
    vector<int> p;
    Dsu(int n){
        p.resize(n);
        iota(p.begin(),p.end(),0);
    }
    int get(int n){
        if(p[n] == n) return n;
        return p[n] = get(p[n]);
    }
    void unite(int a,int b){
        int p1 = get(a);
        int p2 = get(b);
        if(p1 != p2){
            p[p2] = p1;
        }
    }
};

class Solution {
public:
    int numSimilarGroups(vector<string>& strs) {
        int n = strs.size();
        int m = strs[0].size();
        Dsu d(n);
        //do some computations
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < n ; j++){
                int cnt = 0;
                for(int k = 0 ; k < m ; k++){
                    if(strs[i][k] != strs[j][k]) cnt++;
                    if(cnt > 2) break;
                }
                //same group
                if(cnt <= 2){
                    d.unite(i,j);
                }
            }
        }
        //find the answer
        int ans = 0;
        for(int i = 0 ; i < n ; i++){
            if(d.p[i] == i){
                ans++;
            }
        }
        return ans;
    }
