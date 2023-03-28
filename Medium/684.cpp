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
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n;
        int m = edges.size();
        for(int i = 0 ; i < m ; i++){
            n = max(n,edges[i][0]);
            n = max(n,edges[i][1]);
        }
        dsu d(n);
        int ans = 0;
        for(int i = 0 ; i < m ; i++){
            bool status = d.unite(edges[i][0]-1,edges[i][1]-1);
            if(!status){
                ans = i;
            }
        }
        return edges[ans];
    }
};