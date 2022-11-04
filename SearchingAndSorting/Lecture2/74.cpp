#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size(),m = matrix[0].size(),s = 0,e = n*m-1;
        while(s <= e){
            int mid = s+(e-s)/2;
            if(matrix[mid/m][mid%m] < target){
                s = mid+1;
            }else if(matrix[mid/m][mid%m] > target){
                e = mid-1;
            }else{
                return true;
            }
        }
        return false;
    }
};