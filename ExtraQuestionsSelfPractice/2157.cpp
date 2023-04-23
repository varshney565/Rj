class Dsu{
    public : 
    vector<int> p,s;
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
        if(p1 == p2) return false;
        if(s[p2] < s[p1]){
            p[p2] = p1;
            s[p1] += s[p2];
            return true;
        }
        p[p1] = p2;
        s[p2] += s[p1];
        return true;
    }
};

class Solution {
public:
    vector<int> groupStrings(vector<string>& words) {
        //returning format
        
        //ans[0] = maximum number of words in a group.
        //ans[1] = total number of groups.
        int n = words.size();
        Dsu d(n);
        unordered_map<string,int> container;
        for(int i = 0 ; i < n ; i++){
            string p = "00000000000000000000000000";
            for(int j = 0 ; j < words[i].size() ; j++){
                p[words[i][j]-'a'] = '1';
            }
            if(container.find(p) == container.end())
                container[p] = i;
            else{
                d.unite(i,container[p]);
                container[p] = i;
            }
        }
        
        for(int i = 0 ; i < n ; i++){
            string p = "00000000000000000000000000";
            vector<int> one;
            vector<int> zer;
            for(int j = 0 ; j < words[i].size() ; j++){
                p[words[i][j]-'a'] = '1';
            }
            //replace
            for(int m = 0 ; m < 26 ; m++){
                if(p[m] == '0'){
                    zer.push_back(m);
                }else{
                    one.push_back(m);
                }
            }
            for(int j = 0 ; j < one.size() ; j++){
                int i1 = one[j];
                p[i1] = '0';
                for(int k = 0 ; k < zer.size() ; k++){
                    int i2 = zer[k];
                    p[i2] = '1';
                    if(container.find(p) != container.end()){
                        d.unite(i,container[p]);
                    }
                    p[i2] = '0';
                }
                p[i1] = '1';
            }
            
            //delete
            for(int j = 0 ; j < 26 ; j++){
                if(p[j] == '1'){
                    p[j] = '0';
                    if(container.find(p) != container.end()){
                        d.unite(i,container[p]);
                    }
                    p[j] = '1';
                }
            }
        }
        int a = 0,b = 0;
        for(int i = 0 ; i < n ; i++){
            if(d.p[i] == i){
                a++;
                b = max(b,d.s[i]);
            }
        }
        return {a,b};
    }
}