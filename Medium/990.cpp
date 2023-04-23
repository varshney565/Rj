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
		int p1 = get(a),p2 = get(b);
		if(p1 == p2) return false;
		p[p1] = p2;
		return true;
	}
};


class Solution {
public:
    bool equationsPossible(vector<string>& equations) {
        int n = equations.size();
        int s = -1;
        for(int i = 0 ; i < n ; i++){
            if(equations[i][1] == '='){
                swap(equations[++s],equations[i]);
            }
        }
        dsu d(26);
        bool ans = true;
        for(int i = 0 ; i < n ; i++){
            int a = equations[i][0]-'a';
            int b = equations[i][3]-'a';
            if(equations[i][1] == '='){
                d.unite(a,b);
            }else{
                int p1 = d.get(a);
                int p2 = d.get(b);
                if(p1 == p2) return false;
            }
        }
        return true;
    }
};
