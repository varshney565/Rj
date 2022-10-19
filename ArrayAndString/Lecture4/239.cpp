#include<bits/stdc++.h>
using namespace std;
/**
 * Brute Force : O(n*k)
 * 
 * Optimised solution 1 : O(nlogn) , O(n)    priority queue
 * Optimised solution 2 : O(nlogk) , O(k)    set
 * Optimised Solution 3 : O(n)     , O(k)    dequeue
 * 
 */
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        // using map
        int n = nums.size();
        // preprocess the elements
        set<int> Window;
        for(int i = 0 ; i < k ; i++){
            while(!Window.empty() && nums[*Window.rbegin()] <= nums[i]){
                Window.erase(*Window.rbegin());
            }
            Window.insert(i);
        }
        vector<int> ans;
        ans.push_back(nums[*Window.begin()]);
        for(int i = k ; i < n ; i++){
            //shrink the window.
            while(!Window.empty() && *Window.begin() <= i-k){
                Window.erase(Window.begin());
            }
            
            //insert the ith element in the window.
            while(!Window.empty() && nums[*Window.rbegin()] <= nums[i]){
                Window.erase(*Window.rbegin());
            }
            Window.insert(i);
            ans.push_back(nums[*Window.begin()]);
        }
        return ans;
        
        
        
        /**
        deque<int> d;
        vector<int> ans;
        int n = nums.size();
        //processing first k elements.
        for(int i = 0 ; i < k ; i++){
            if(d.size() == 0){
                d.push_back(i);
            }else{
                while(d.size() > 0 && nums[d.back()] <= nums[i]){
                    d.pop_back();
                }
                d.push_back(i);
            }
        }
        ans.push_back(nums[d.front()]);
        //processing the remaining elements
        for(int i = k ; i < n ; i++){
            //remove the elements which are not part of the current window.
            while(d.size() > 0 && d.front() <= i-k){
                d.pop_front();
            }
            //process the ith element and insert it in dequeue.
            if(d.size() == 0){
                d.push_back(i);
            }else{
                while(d.size() > 0 && nums[d.back()] <= nums[i]){
                    d.pop_back();
                }
                d.push_back(i);
            }
            ans.push_back(nums[d.front()]);
        }
        return ans;
        **/
    }
};