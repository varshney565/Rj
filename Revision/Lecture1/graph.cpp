#include<bits/stdc++.h>
using namespace std;

class Graph {
    public : 
    class Edge {
        public : 
        int v,w;
        Edge(int v,int w) {
            this->v = v;
            this->w = w;
        }
    };

    void addEdge(vector<vector<Edge>> &adj,int u,int v,int w) {
        adj[u].push_back(Edge(v,w));
        adj[v].push_back(Edge(u,w));
    }

    void display(vector<vector<Edge>> &adj) {
        int V = adj.size();
        for(int i = 0 ; i < V ; i++) {
            cout<<i<<"->";
            for(int j = 0 ; j < adj[i].size() ; j++) {
                cout<<"("<<adj[i][j].v<<","<<adj[i][j].w<<")"<<",";
            }
            cout<<"\n";
        }
    }

    int FindEdge(vector<vector<Edge>> &adj,int u,int v) {
        int V = adj.size();
        for(int j = 0 ; j < adj[u].size() ; j++) {
            if(adj[u][j].v == v) {
                return j;
            }
        }
        return -1;
    }

    void removeEdge(vector<vector<Edge>> &adj,int u,int v) {
        /**
         * Removing the Edge from adj[u].
        */
        int index_u = FindEdge(adj,u,v);
        if(index_u == -1) {
            return ;
        }
        swap(adj[u][index_u],adj[u][adj[u].size()-1]);
        adj[u].pop_back();

        /**
         * Removing the Edge from adj[v]
        */
        int index_v = FindEdge(adj,v,u);
        swap(adj[v][index_v],adj[v][adj[v].size()-1]);
        adj[v].pop_back();
    }

    void removeVertex(vector<vector<Edge>> &adj,int u) {
        int n = adj[u].size();
        for(int j = n - 1 ; j >= 0 ; j--) {
            int v = adj[u][j].v;
            int idx = FindEdge(adj,v,u);
            swap(adj[v][idx],adj[v][adj[v].size()-1]);
            adj[v].pop_back();
            adj[u].pop_back();
        }
    }

    void constructGraph() {
        int V = 9;
        vector<vector<Edge>> adj(V);
        addEdge(adj,0,1,10);
        addEdge(adj,0,3,10);
        addEdge(adj,1,2,10);
        addEdge(adj,2,3,40);
        addEdge(adj,3,4,2);
        addEdge(adj,2,7,2);
        addEdge(adj,7,8,3);
        addEdge(adj,2,8,4);
        addEdge(adj,4,5,2);
        addEdge(adj,5,6,3);
        addEdge(adj,4,6,8);
        display(adj);
        removeVertex(adj,2);
        display(adj);
    }
};

int main() {
    Graph g = Graph();
    g.constructGraph();
}