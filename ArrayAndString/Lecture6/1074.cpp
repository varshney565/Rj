#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int count(int i,int j,vector<vector<int>>&matrix,int target){
        int m = matrix[0].size();
        int ans = 0;
        int sum = 0;
        map<int,int> cnt;
        for(int k = 0 ; k < m ; k++){
            int cur_sum = matrix[j][k]-(i?matrix[i-1][k]:0);
            sum += cur_sum;
            if(sum == target)
                ans++;
            ans += cnt[sum-target];
            cnt[sum]++;
        }
        return ans;
    }
    
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        int ans = 0;
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(i)
                    matrix[i][j] += matrix[i-1][j];
            }
        }
        
        for(int i = 0 ; i < n ; i++){
            for(int j = i ; j < n ; j++){
                ans += count(i,j,matrix,target);
            }
        }
        return ans;
    }
};