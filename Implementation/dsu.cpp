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
