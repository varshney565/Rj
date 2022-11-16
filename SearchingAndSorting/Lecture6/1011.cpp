#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int shipWithinDays(vector<int>& weights, int Redays) {
        int sw = *max_element(weights.begin(),weights.end());
        int ew = int(1e7);
        while(sw <= ew){
            int midw = (sw+ew)/2;
            int days = 1;
            int sum = 0;
            for(int i = 0 ; i < weights.size() ; i++){
                if(sum + weights[i] > midw){
                    days++;
                    sum = weights[i];
                }else{
                    sum += weights[i];
                }
            }
            
            if(days <= Redays){
                ew = midw-1;
            }else{
                sw = midw+1;
            }
        }
        return sw;
    }
};

