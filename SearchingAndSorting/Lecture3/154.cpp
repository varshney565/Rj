#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int s = 0,e = nums.size()-1;
        while(s < e){
            int mid = (s+e)/2;
            if(nums[mid] == nums[s] && nums[mid] == nums[e]) e--;
            else if(nums[mid] <= nums[e]) e = mid;
            else s = mid+1;
        }
        return nums[e];
    }
};