#include<bits/stdc++.h>
#pragma GCC optimise("Ofast")
#pragma GCC target("avx","avx2","fma")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
using namespace std;
#define int long long
#define all(x) x.begin(),x.end()
#define pi pair<int,int>
#define ff first
#define ss second

#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" "; _print(x); cerr << "\n";
#else
#define debug(x)
#endif

void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(bool t) {cerr << t;}

template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(multimap <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
inline void read(int &n,vector<int> &v){for(int i = 0 ; i < n ; i++) cin>>v[i];}
inline void print(int &n,vector<int> &v){for(int i = 0 ; i < n ; i++) cout<<v[i]<<" ";cout<<"\n";}
inline void read(int &n,int &m,vector<vector<int>> &v){for(int i=0;i<n;i++){for(int j=0;j<m;j++){cin>>v[i][j];}}}
inline void print(int &n,int &m,vector<vector<int>> &v){for(int i=0 ;i<n;i++){for(int j=0;j<m;j++){cout<<v[i][j]<<" ";}cout<<"\n";}}


//some commanly used functions
bool isPrime(int n){if(n==2||n==3)return true;if(n==1||n%2==0||n%3==0)return false;for(int i=5 ;i*i<=n;i+=6)if(n%i==0||n%(i+2)==0)return false;return true;}
/*
    
*/

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

void solve(){
    int n,m,k;cin>>n>>m>>k;
    vector<vector<int>> edges;
    for(int i = 0 ; i < m ; i++){
        int u,v,w;cin>>u>>v>>w;
        u--,v--;
        edges.push_back({u,v,w});
    }
    sort(all(edges),[&](const vector<int>& a,const vector<int>& b){
        return a[2] < b[2];
    });


    //Logic
    Dsu d(n);
    vector<int> costs;
    for(int i = 0 ; i < m ; i++){
        if(d.unite(edges[i][0],edges[i][1])){
            costs.push_back(edges[i][2]);
        }
    }
    int cnt = 0;
    for(int i = 0 ; i < n ; i++){
        if(d.p[i] == i) cnt++;
        if(cnt > 1){
            cout<<"-1\n";return;
        }
    }
    //only one component
    int ans = 0;
    int sum = 0;
    sum = accumulate(all(costs),sum);
    int l = costs.size()-1;
    while(sum > k && l >= 0){
        sum -= costs[l];
        sum++;
        ans++;
        l--;
    }

    if(sum > k){
        cout<<"-1\n";
    }else{
        cout<<ans<<"\n";
    }
}

signed main()
{
    #ifndef ONLINE_JUDGE
        freopen("./../IO/input.txt","r",stdin);
        freopen("./../IO/output.txt","w",stdout);
        freopen("./../IO/error.txt", "w", stderr);
    #endif

    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    cerr<<"time taken : "<<(float)clock()/CLOCKS_PER_SEC<<" secs"<<"\n";
    return 0;
}