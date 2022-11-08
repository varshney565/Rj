#include<bits/stdc++.h>
using namespace std;

int twoSumClosest(vector<int> &nums1,vector<int>& nums2,int target){
    int n1 = nums1.size();
    int n2 = nums2.size();
    /**
     * Approach 1 : 
     * using binary search : 
     * 
     * for each element in the second array search for target-nums2[i]
     * if it is present count all such target-nums2[i]
     * mean find the first and last occurence of target-nums2[i]
     * and do ans += lastOcc - firstOcc+1
     * 
     * 
     * Approach 2 : 
     * using map : 
     * 
     * insert all elements of the first array in the map.
     * and for each element in the second array do ans += Container[tar-nums2[i]];
     * 
     * Container is the name of map that holds frequency of all elements in the nums1 array.
     */
    map<int,int> Container;
    int ans = 0;
    for(auto x : nums1) Container[x]++;
    for(auto x : nums2) ans += (Container.find(target-x) != Container.end() ? Container[target-x] : 0);
    return ans;
}

int main(){

}