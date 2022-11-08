#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        unordered_map<int,int> Container;
        
        for(int i = 0 ; i < nums2.size() ; i++){
            for(int j = 0 ; j < nums1.size() ; j++){
                Container[nums1[j]+nums2[i]]++;
            }
        }
        
        int ans = 0;
        for(int i = 0 ; i < nums3.size() ; i++){
            for(int j = 0 ; j < nums4.size() ; j++){
                int s = nums3[i]+nums4[j];
                if(Container.find(-s) != Container.end())
                    ans += Container[-s];
            }
        }
        return ans;
    }
};