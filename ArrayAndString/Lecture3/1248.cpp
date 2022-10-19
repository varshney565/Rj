#include<bits/stdc++.h>
using namespace std;
int numberOfSubarrays(vector<int>& nums, int k) {
    //total subarray with exactly k odd numbers in it = atmost k - atmost (k-1)
    int n = nums.size();
    auto atmostK = [&](int k){
        int count = 0;
        int en = 0;
        int st = 0;
        int ans = 0;
        while(en < n){
            if(nums[en]%2)
                count++;
            while(count > k){
                if(nums[st]%2)
                    count--;
                st++;
            }
            ans += (en-st+1);
            en++;
        }
        return ans;
    };
    return atmostK(k)-atmostK(k-1);
}