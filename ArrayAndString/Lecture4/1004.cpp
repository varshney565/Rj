#include<bits/stdc++.h>
using namespace std;

int longestOnes(vector<int>& nums, int k) {
    /**
    Find a maximum length subarray such that it has at most k zero's.
    */
    int count = 0;
    int s = 0;
    int e = 0;
    int ans = 0;
    while(e < nums.size()){
        if(nums[e] == 0) count++;
        while(count > k){
            if(nums[s] == 0)
                count--;
            s++;
        }
        ans = max(ans,e-s+1);
        e++;
    }
    return ans;
}