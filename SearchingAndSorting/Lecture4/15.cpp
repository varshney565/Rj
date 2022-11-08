#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        int i = 0;
        while(i < n-2){
            int si = i+1,ei = n-1;
            while(si < ei){
                if(nums[i]+nums[si]+nums[ei] > 0) ei--;
                else if(nums[i]+nums[si]+nums[ei] < 0) si++;
                else{
                    ans.push_back({nums[i],nums[si],nums[ei]});
                    si++;
                    ei--;
                    while(si < ei && nums[si] == nums[si-1]) si++;
                    while(si < ei && nums[ei] == nums[ei+1]) ei--;
                }
            }
            i++;
            while(i < n-2 && nums[i] == nums[i-1])
                i++;
        }
        return ans;
    }
};