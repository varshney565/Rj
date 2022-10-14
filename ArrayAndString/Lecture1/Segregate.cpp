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

/**
 * three variations
 * 1.segregate 0's and 1's.
 * 2.segregate 0's and 1's and 2's.
 * 3.segregate pos and neg.
 */


/**
 * 1.segregate 0's and 1's. 
 */

void ZeroAndOne(){
    int n;
    cin>>n;
    vector<int> v(n);
    read(n,v);
    int prev = -1;
    int i = 0;
    while(i < n){
        if(v[i] == 0){
            prev++;
            swap(v[prev],v[i]);
        }
        i++;
    }
    print(n,v);
}


/**
 * 2.segregate 0's and 1's and 2's.
*/

void ZeroOneTwo(){
    int n;
    cin>>n;
    vector<int> v(n);
    read(n,v);
    int zero = -1;
    int one = -1;
    for(int two = 0 ; two < n ; two++){
        if(v[two] == 2)
            continue;
        else if(v[two] == 1){
            swap(v[two],v[++one]);
        }else if(v[two] == 0){
            swap(v[two],v[++zero]);
            swap(v[two],v[++one]);
        }
    }
    print(n,v);
}

/**
 * 3.segregate pos and neg.
 */
void posNeg(){
   int n;
   cin>>n;
   vector<int> v(n);
   read(n,v);
   int prev = -1;
   int i = 0;
   while(i < n){
    if(v[i] < 0){
        prev++;
        swap(v[prev],v[i]);
    }
    i++;
   }
   print(n,v);
}

signed main()
{
    #ifndef ONLINE_JUDGE
        freopen("../../IO/input.txt","r",stdin);
        freopen("../../IO/output.txt","w",stdout);
        freopen("../../IO/error.txt", "w", stderr);
    #endif

    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    ZeroOneTwo();
    cerr<<"time taken : "<<(float)clock()/CLOCKS_PER_SEC<<" secs"<<"\n";
    return 0;
}

