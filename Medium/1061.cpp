class Dsu{
    public:
    vector<int> p;
    Dsu(){
        p.resize(26);
        iota(p.begin(),p.end(),0);
    }
    
    int get(int n){
        if(p[n] == n) return n;
        return p[n] = get(p[n]);
    }
    
    bool unite(char a,char b){
        int x = a-'a',y = b-'a';
        int p1 = get(x);
        int p2 = get(y);
        if(p1 == p2) return false;
        if(p1 < p2){
            p[p2] = p1;
        }else{
            p[p1] = p2;
        }
        return true;
    }
};
class Solution {
public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        int n = s1.size();
        Dsu d;
        for(int i = 0 ; i < n ; i++){
            d.unite(s1[i],s2[i]);
        }
        string ans = "";
        for(int i = 0 ; i < baseStr.size() ; i++){
            int p = d.get(baseStr[i]-'a');
            ans += (p+'a');
        }
        return ans;
    }
};