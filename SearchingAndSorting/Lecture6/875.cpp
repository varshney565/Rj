#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int s = 1;
        int e = (int)1e9;
        while(s <= e){
            int BananaPerHour = (s+e)/2;
            long long currentHour = 0;
            for(int i = 0 ; i < n ; i++){
                currentHour += ((long long)piles[i]+BananaPerHour-1)/BananaPerHour;
            }
            if(currentHour > h){
                s = BananaPerHour + 1;
            }else{
                e = BananaPerHour - 1;
            }
        }
        return s;
    }
};

