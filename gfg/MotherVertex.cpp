//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution 
{
    public:
    //Function to find a Mother Vertex in the Graph.
	int findMotherVertex(int n, vector<int> graph[]){
    	vector<int> outTimeNodes;
    	vector<bool> visited(n,false);
    	function<void(int)> dfs1 = [&](int src){
    		visited[src] = true;
    		for(auto child : graph[src]){
    			if(!visited[child]){
    				dfs1(child);
    			}
    		}
    		outTimeNodes.push_back(src);
    	};
    	for(int v = 0 ; v < n ; v++){
    		if(!visited[v])
    			dfs1(v);
    	}
    	
    	int t = outTimeNodes.back();
    	int cnt = 0;
    	for(int i = 0 ; i < n ; i++) visited[i] = false;
    	
    	function<void(int)> dfs = [&](int src){
    		visited[src] = true;
    		cnt++;
    		for(auto child : graph[src]){
    			if(!visited[child]){
    				dfs(child);
    			}
    		}
    	};
    	dfs(t);
    	if(cnt == n) return t;
    	return -1;
	}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
		}
		Solution obj;
		int ans = obj.findMotherVertex(V, adj);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends