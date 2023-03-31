class Dsu{
    public : 
    vector<int> p;
    Dsu(int n){
        p.resize(n);
        iota(all(p),0);
    }

    int get(int n){
        if(p[n] == n) return n;
        return p[n] = get(p[n]);
    }

    bool unite(int a,int b){
        int p1 = get(a);
        int p2 = get(b);
        if(p1 == p2){
            return false;
        }
        p[p1] = p2;
        return true;
    }
};

vector<vector<int>> kurshkal(int n,vector<vector<int>> &edges){
    sort(edges.begin(),edges.end(),[&](const vector<int> &a,const vector<int> &b){
        return a[2] < b[2];
    });
    vector<vector<int>> ans;
    Dsu d(n);
    for(int i = 0 ; i < edges.size() ; i++){
        if(d.unite(edges[i][0],edges[i][1])){
            ans.push_back(edges[i]);
        }
    }
    return ans;
}

int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> edges;
    for(int i = 0 ; i < m ; i++){
        int u,v,w;
        cin>>u>>v>>w;
        edges.push_back({u,v,w});
    }
    auto ans = kurshkal(n,edges);
    //print ans
    return 0;
}