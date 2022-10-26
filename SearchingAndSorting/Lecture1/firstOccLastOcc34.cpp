#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int i = 0;
        int j = n-1;
        int firstOcc = -1;
        while(i <= j){
            int mid = i+(j-i)/2;
            if(nums[mid] > target){
                j = mid-1;
            }else if(nums[mid] < target){
                i = mid+1;
            }else{
                if(mid == 0 || nums[mid-1] != nums[mid]){
                    firstOcc = mid;
                    break;
                }
                j = mid-1;
            }
        }
        if(firstOcc == -1) return {-1,-1};
        int lastOcc = -1;
        i = 0;
        j = n-1;        
        while(i <= j){
            int mid = i+(j-i)/2;
            if(nums[mid] > target){
                j = mid-1;
            }else if(nums[mid] < target){
                i = mid+1;
            }else{
                if(mid == n-1 || nums[mid+1] != nums[mid]){
                    lastOcc = mid;
                    break;
                }
                i = mid+1;
            }
        }
        return {firstOcc,lastOcc};
    }
};