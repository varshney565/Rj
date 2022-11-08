#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n = arr.size();
        vector<int> ans;
        // find the upper bound and lower bound of x and start from there.
        sort(arr.begin(),arr.end());
        int s = 0,e = n-1;
        while(s <= e){
            int mid = (s+e)/2;
            if(arr[mid] > x) e = mid-1;
            else s = mid+1;
        }
        //now s is pointing to upper_bound of x in arr.
        /**
         * got the upper_bound and now checking what all elements needed to be taken and after that 
         * sorting the answer array. 
         */
        while(s < n && e >= 0 && ans.size() < k){
            int val1 = abs(arr[s]-x);
            int val2 = abs(arr[e]-x);
            if(val1 < val2){
                ans.push_back(arr[s]);
                s++;
            }else if(val2 <= val1){
                ans.push_back(arr[e]);
                e--;
            }
        }
        while(s < n && ans.size() < k){
            ans.push_back(arr[s]);
            s++;
        }
        while(e >= 0 && ans.size() < k){
            ans.push_back(arr[e]);
            e--;
        }
        sort(ans.begin(),ans.end());
        /**
         * or as i found the upper_bound.now just take a window of size 2*k (k elements on right side of 
         * upper_bound and k on left side of upper_bound) and now start shrinking this window.
         * 
         * and stop the loop when length of the window becomes k and after that return that window.
         */
        return ans;
    }
};