// https://practice.geeksforgeeks.org/problems/maximum-sum-rectangle2948/1
//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int findMaxSum(int i,int j,int R,int C,vector<vector<int>>&nums){
        int sum = 0;
        int ans = (int)-1e9;
        for(int k = 0 ; k < C ; k++){
            int cur_sum = nums[j][k]-(i?nums[i-1][k]:0);
            sum = max(sum+cur_sum,cur_sum);
            ans = max(ans,sum);
        }
        return ans;
    }
    
    int maximumSumRectangle(int R, int C, vector<vector<int>> nums){
        int ans = (int)-1e9;
        for(int i = 0 ; i < R ; i++){
            for(int j = 0 ; j < C ; j++){
                if(i)
                    nums[i][j] += nums[i-1][j];
            }
        }
        
        for(int i = 0 ; i < R ; i++){
            for(int j = i ; j < R ; j++){
                ans = max(ans,findMaxSum(i,j,R,C,nums));
            }
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M;
        cin >> N >> M;
        vector<vector<int>> v(N, vector<int>(M));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++) cin >> v[i][j];
        Solution ob;
        cout << ob.maximumSumRectangle(N, M, v) << "\n";
    }
}
// } Driver Code Ends