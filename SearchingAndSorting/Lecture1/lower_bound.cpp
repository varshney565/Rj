#include<bits/stdc++.h>
using namespace std;

int lower_bound(vector<int>&v,int n,int tar){
    int i = 0;
    int j = n-1;
    while(i <= j){
        int mid = i+(j-i)/2;
        if(v[mid] < tar){
            i = mid+1;
        }else if(v[mid] >= tar){
            j = mid-1;
        }
        /**
         * for upper_bound 
         */

        // if(v[mid] <= tar){
        //     i = mid+1;
        // }else if(v[mid] > tar){
        //     j = mid-1;
        // }
    }
    return i;
}

int main(){
    int n;cin>>n;
    vector<int> v(n);
    for(int i = 0 ; i < n ; i++) cin>>v[i];
    int tar;cin>>tar;
    int idx = lower_bound(v,n,tar);
    cout<<idx<<"\n";
    return 0;
}