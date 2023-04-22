        /**
 * author : shivam varshney
 * UIET KURUKSHETRA UNIVERSITY
 * ∑.⌣
 * */

#include<bits/stdc++.h>
#pragma GCC optimise("Ofast")
#pragma GCC target("avx","avx2","fma")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
using namespace std;
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
/*

    

*/

class Edge{
    public : 
    int v;
    int w;
    Edge(int a,int b){
        v = a;
        w = b;
    }
};

void solve(){
   int n,m,k,x;
   cin>>n>>m>>k>>x;
   vector<int> choclateCities(n,false);
   for(int i = 0 ; i < k ; i++) {
    int t;cin>>t;choclateCities[--t] = true;
   }
   vector<vector<Edge>> graph(n);
   for(int i = 0 ; i < m ; i++){
    int u,v,w;cin>>u>>v>>w;
    u--;v--;
    graph[u].push_back(Edge(v,w));
    graph[v].push_back(Edge(u,w));
   }
   int src;cin>>src;
   int dest;cin>>dest;
   src--;
   dest--;
   vector<int> d1(n,INT_MAX);
   vector<int> d2(n,INT_MAX);
   d1[src] = 0;
   d2[dest] = 0;
   auto dj = [&](int src,vector<int> &dis){
    set<pair<int,int>> pq;
    pq.insert({0,src});
    while(!pq.empty()){
        auto front = *pq.begin();
        pq.erase(front);
        int u = front.second;
        int wsf = front.first;
        if(dis[u] < wsf) continue;
        for(auto child : graph[u]){
            int v = child.v;
            int w = child.w;
            if(dis[v] > wsf + w){
                pq.erase({dis[v],v});
                dis[v] = wsf + w;
                pq.insert({dis[v],v});
            }
        }
    }
   };
   dj(src,d1);
   dj(dest,d2);
   int ans = INT_MAX;
   for(int i = 0 ; i < n ; i++){
    if(choclateCities[i] && d1[i] < INT_MAX && d2[i] < INT_MAX){
        if(d2[i] < x)
            ans = min(ans,d1[i]+d2[i]);
    }
   }
   if(ans < INT_MAX){
    cout<<ans<<"\n";
   }else{
    cout<<"-1\n";
   }
}

signed main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    cerr<<"time taken : "<<(float)clock()/CLOCKS_PER_SEC<<" secs"<<"\n";
    return 0;
}

