#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int numRabbits(vector<int>& answers) {
        int n = answers.size();
        int ans = 0;
        map<int,int> cnt;
        for(int i = 0 ; i < n ; i++){
            cnt[answers[i]]++;
        }
        //5 --> 7
        for(auto x : cnt){
            int a = x.first;
            int b = x.second;
            if(b%(a+1) == 0)
                ans += b;
            else
                ans += b-b%(a+1)+a+1;
        }
        return ans;
    }
};