#include<bits/stdc++.h>
using namespace std;

long long max(long long a,long long b){
    return (a<b)?b:a;
}
class Solution {
public:
    int kConcatenationMaxSum(vector<int>& arr, int k) {
        /**
        a) a1 a2 a3 a4 a5
        b) (part of a1) a2 a3 a4 (part of a5)
        c) maximum circuler subarray sum
        */
        const int mod = 1e9+7;
        int n = arr.size();
        int sum = 0;
        int gMin = int(1e9);
        int gMax = int(-1e9);
        int cMinSum = 0;
        int cMaxSum = 0;
        int gsum = 0;
        for(int i = 0 ; i < n ; i++){
            gsum += arr[i];
        }
        int maxSuf = gsum;
        int maxPre = int(-1e9);
        for(int i = 0 ; i < n ; i++){
            sum += arr[i];
            maxSuf = max(maxSuf,gsum-sum);
            maxPre = max(sum,maxPre);
            cMinSum = min(cMinSum+arr[i],arr[i]);
            cMaxSum = max(cMaxSum+arr[i],arr[i]);
            gMax = max(gMax,cMaxSum);
            gMin = min(gMin,cMinSum);
        }
        
        if(k == 1) return gMax;
        int value1 = max(gMax,sum-gMin);        //Maximum subarray sum.
        long long value2 = (long long)sum*k;
        long long value3 = (long long)(k-2)*sum+maxSuf+maxPre;
        long long ans = max(max(value1,value2),value3);
        return ans%mod;
    }
};