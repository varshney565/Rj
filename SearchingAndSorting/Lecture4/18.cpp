#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        for(int i = 0 ; i < n-3 ; ){
            for(int j = i + 1 ; j < n-2 ; ){
                int s = j+1,e = n-1;
                while(s < e){
                    long long sum = (long long)nums[i]+nums[j]+nums[s]+nums[e];
                    if(sum > target) e--;
                    else if(sum < target) s++;
                    else{
                        ans.push_back({nums[i],nums[j],nums[s],nums[e]});
                        s++;
                        e--;
                        while(s < e && nums[s] == nums[s-1]) s++;
                        while(s < e && nums[e] == nums[e+1]) e--;
                    }
                }
                j++;
                while(j < n-2 && nums[j] == nums[j-1]) j++;
            }
            i++;
            while(i < n-3 && nums[i] == nums[i-1]) i++;
        }
        return ans;
    }
};