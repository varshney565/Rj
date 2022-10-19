#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n = nums.size();
        map<int,int> cnt;
        int sum = 0;
        int ans = 0;
        for(int i = 0 ; i < n ; i++){
            sum += nums[i];
            //as neagitive elements can be there.
            int rem = (sum%k+k)%k;
            if(rem == 0)
                ans++;
            if(cnt.find(rem) != cnt.end())
                ans += cnt[rem];
            cnt[rem]++;
        }
        return ans;
    }
};

/**
 * for printing every subarray instead of couting insert index value at each prefix sum value.
 * 
 * 
 * prefix sum       indexes
 * 1 :              [0,1]
 * 2 :              [5]
 * 3 :              [2,4]
 * 4 :              [3]
 * 5 :              [6]
 */