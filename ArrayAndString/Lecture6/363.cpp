#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMax(int i,int j,vector<vector<int>>&matrix,int k){
        int m = matrix[0].size();
        int ans = (int)-1e9;
        //find the maximum sum of subarray with sum atmost k
        int sum = 0;
        int en = 0;
        set<int> container;
        container.insert(0);
        while(en < m){
            sum += matrix[j][en]-(i?matrix[i-1][en]:0);
            auto it = container.lower_bound(sum-k);
            if(it != container.end())
                ans = max(ans,sum-*it);
            container.insert(sum);
            en++;
        }
        return ans;
    }
    
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int m = matrix[0].size();
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(i)
                    matrix[i][j] += matrix[i-1][j];
            }
        }
        
        int ans = (int)-1e9;
        for(int i = 0 ; i < n ; i++){
            for(int j = i ; j < n ; j++){
                ans = max(ans,findMax(i,j,matrix,k));
            }
        }
        return ans;
    }
};