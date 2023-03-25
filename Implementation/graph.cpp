        /**
 * author : shivam varshney
 * UIET KURUKSHETRA UNIVERSITY
 * 
 * Keep It Simple Silly (KISS)
 *
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


//some commanly used functions
bool isPrime(int n){if(n==2||n==3)return true;if(n==1||n%2==0||n%3==0)return false;for(int i=5 ;i*i<=n;i+=6)if(n%i==0||n%(i+2)==0)return false;return true;}
/*

    TODO :

    a) construct the graph and do following things on the graph
        1. create a function to print the graph and ATC.
        2. remove an edge from graph.
        3. remove an vertex from the graph.
        4. hasPath function.
        5. FinalAllPaths or tatal paths.
        6. preorder and postorder of the graph
        7. find the heavy path btw source and destination.
        8. Hamiltonian path.
        9. Hamiltonian cycle.
*/
class Graph{

    class Edge{
        public:
            int v,w;
            Edge(int v,int w){
                this->v = v;
                this->w = w;
            }
    };

    public : 
        vector<vector<Edge>>graph;

        void addEdge(int u,int v,int w){
            graph[u].push_back(Edge(v,w));
            graph[v].push_back(Edge(u,w));
        }

        /**
         * constructing the graph,will need total number of vertices that are present in the graph
        */
        Graph(int n){
            graph.resize(n);
        }

        /**
         * print the graph
        */

       void printGraph(){
        int n = graph.size();
        for(int i = 0 ; i < n ; i++){
            cout<<i<<" : ";
            for(int j = 0 ; j < graph[i].size() ; j++){
                cout<<"("<<graph[i][j].v<<","<<graph[i][j].w<<")"<<"#";
            }
            cout<<"\n";
        }
       }

       /**
        * remove an edge from the graph
       */
      void removeEdge(int u,int v){
        /**
         * logic 
         * find that node and now swap that node with the last node of the graph
        */
        int m = graph[u].size();
        for(int i = 0 ; i < m ; i++){
            if(graph[u][i].v == v){
                //now delete that edge
                swap(graph[u][i],graph[u][m-1]);
                graph[u].pop_back();
                break;
            }
        }
        int n = graph[v].size();
        for(int i = 0 ; i < n ; i++){
            if(graph[v][i].v == u){
                //now delete that edge
                swap(graph[v][i],graph[v][n-1]);
                graph[v].pop_back();
                break;
            }
        }
      }

      /**
       * remove an vertex from the graph.
      */
     void removeVertex(int u){
        //checks if any vertex is connected with u and is so remove that edge
        int n = graph.size();
        for(int i = 0 ; i < n ; i++){
            if(i == u){
                graph[i].clear();
                continue;
            }
            for(int j = 0 ; j < graph[i].size() ; j++){
                auto edge = graph[i][j];
                if(edge.v == u){
                    //remove it.
                    swap(graph[i][j],graph[i][graph[i].size()-1]);
                    graph[i].pop_back();
                }
            }
        }
     }

     /**
      * haspath 
     */

    /**
     * dfs call
     * 
     * mark it as visited
     * call on all the unvisited child nodes
     * unmark as unvisited only if needed -- like in case all the paths we need to unmark it.
     * 
    */

    bool hasPath(int u,int v){
        vector<bool> visited(graph.size(),false);
        function<bool(int,int)> helper = [&](int u,int v){
            if(u == v) return true;
            visited[u] = true;
            for(auto child : graph[u]){
                if(!visited[child.v]){
                    auto ans = helper(child.v,v);
                    if(ans) return ans;
                }
            }
            return false;
        };
        return helper(u,v);
    }

    /**
     * generate all the paths and also return the count
     * 
     * in the wrost case complexity will be (V+E)*V!
     * 
     * in the wrost case graph will have V-1 edges.
     * and complexity of one dfs is O(V+E)
     * so overall complexity will be O(V+E)*total number of possible paths in wrost case
     * 
     * so total number of possible paths in wrost case = 
     * 
     * V*(V-1)*(V-2)*.......*1 = V!
     * 
     * total choices for first vertex = V
     * total choices for second vertex = V-1
     * total choices for third vertex = V-2
     * .....
     * .....
     * 
     * 
     * 
    */

    int allPaths(int u,int v){
        vector<bool> visited(graph.size(),false);
        function<int(int,int,string)> helper = [&](int u,int v,string psf){
            if(u == v) {
                cout<<psf+to_string(u)<<"\n";return 1;
            }
            visited[u] = true;
            //go to all the unvisited vertices.
            int count = 0;
            for(auto child : graph[u]){
                if(!visited[child.v]){
                    count += helper(child.v,v,psf+to_string(u));
                }
            }
            visited[u] = false;
            return count;
        };
        return helper(u,v,"");
    }

    /**
     * preorder of the graph
    */

    void preorder(int src){
        vector<int> visited(graph.size(),false);
        function<void(int,string,int)> helper = [&](int src,string psf,int wsf){
            //print the root
            cout<<src<<" -> "<<psf+to_string(src)<<" @ "<<wsf<<"\n";
            visited[src] = true;
            //print all the childs
            for(auto child : graph[src]){
                if(!visited[child.v])
                    helper(child.v,psf+to_string(src),wsf+child.w);
            }
            visited[src] = false;
        };
        helper(src,"",0);
    }

    /**
     * find the heavy path
    */
   int heavyPath(int u,int v){
    vector<bool> visited(graph.size(),false);
    function<int(int,int,int)> helper = [&](int u,int v,int wsf){
        if(u == v) return wsf;
        visited[u] = true;
        int ans = -1;
        for(auto child : graph[u]){
            if(!visited[child.v]){
                ans = max(ans,helper(child.v,v,wsf+child.w));
            }
        }
        visited[u] = false;
        return ans;
    };
    return helper(u,v,0);
   }

   /**
    * check whether their exixsts any edge between u and v
   */
   int isEdge(int u,int v){
    int i = 0;
    for(auto child : graph[u]){
        if(child.v == v){
            return i;
        }
        i++;
    }
    return -1;
   }

   void hamilton(int u){
    //print all the hamilton path and hamilton cycle.
    vector<bool> visited(graph.size(),false);

    function<void(int,int,string)> helper = [&](int src,int count,string psf){
        //base case
        
        if(count == graph.size()){
            cout<<psf+to_string(src);
            //check whether it is hamilton cycle or path.
            //means check whether there exists path btw src and u.
            if(isEdge(src,u) >= 0){
                cout<<"*";
            }
            cout<<"\n";
            return;
        }

        visited[src] = true;
        //dfs call
        for(auto child : graph[src]){
            if(!visited[child.v]){
                helper(child.v,count+1,psf+to_string(src));
            }
        }
        visited[src] = false;
    };
    helper(u,1,"");
   }

   int gcc();
   void bfs(int src);
   void bfs2(int src);//fast because it does't care about cycle
   bool bipartitie();
};

#include"bfs.cpp"
#include"bfs2.cpp"
#include"gcc.cpp"
#include"bipartitie.cpp"

void solve(){
   Graph g(9);
   /**
    * a) construct the graph
   */
   g.addEdge(0,1,10);
   g.addEdge(0,3,10);
   g.addEdge(2,1,10);
   g.addEdge(3,2,40);
   g.addEdge(2,7,2);
   g.addEdge(2,8,4);
   g.addEdge(7,8,3);
   g.addEdge(3,4,2);
   g.addEdge(4,5,2);
   g.addEdge(5,6,3);
   g.addEdge(4,6,8);
   g.addEdge(8,6,12);
   g.printGraph();

   cout<<"path btw 0 and 6 : "<<g.hasPath(0,6)<<"\n";
   cout<<"and all the paths are : \n";
   g.allPaths(0,6);
   cout<<"preorder of the graph \n";
   g.preorder(0);
   cout<<"Hamilton Path and cycle: \n";
   g.hamilton(8);
   cout<<"BFS : \n";
   g.bfs2(0);
   cout<<"bipartitie : ";
   cout<<g.bipartitie()<<"\n";
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
    int T;
    cin>>T;
    while(T--){
        solve();
    }
    cerr<<"time taken : "<<(float)clock()/CLOCKS_PER_SEC<<" secs"<<"\n";
    return 0;
}