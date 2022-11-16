#include<bits/stdc++.h>
using namespace std;

int cake(vector<int> radius,int numGuest){
    int n = radius.size();
    double s = 0;
    double e = 1e5;
    const double pi = 3.141593;
    while(e-s > 1e-4){
        double areaBar = (s+e)/2.0;
        int g = 0;
        for(int i = 0 ; i < n ; i++){
            g += radius[i]*pi*pi/areaBar;
        }
        if(g >= numGuest){
            s = areaBar;
        }else{
            e = areaBar-1e-4;
        }
    }
    return s;
}