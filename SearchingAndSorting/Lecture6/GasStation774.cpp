//Lint Code 848
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    double minmaxGasDist(vector<int> &stations, int k) {
        double s = 1e-6;
        double e = 1e9;
        int n = stations.size();
        while((e-s) > 1e-6){
            double mid = (s+e)/2.0;
            int K_used = 0;
            for(int i = 1 ; i < n ; i++){
                double diff = stations[i]-stations[i-1];
                if(diff > mid){
                    K_used += ceil(diff/mid)-1;
                }
            }
            if(K_used > k){
                s = mid+1e-6;
            }else{
                e = mid;
            }
        }
        return s;
    }
};