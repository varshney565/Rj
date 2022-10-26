#include<bits/stdc++.h>
using namespace std;

int Nearest(vector<int>&v,int n,int tar){
    int si = 0;
    int en = n-1;
    while(si <= en){
        int mid = si+(en-si)/2;
        if(v[mid] <= tar){
            si = mid+1;
        }else if(v[mid] > tar){
            en = mid-1;
        }
    }
    //si is the ceil of (target) means upper_bound.
    //ei will either be less than or equal to target.
    if(si == 0) return v[si];
    if(si == n) return v[n-1];
    return (abs(v[si]-tar) < abs(v[en]-tar))?v[si]:v[en];
}

int main(){
    int n;cin>>n;
    vector<int> v(n);
    for(int i = 0 ; i < n ; i++) cin>>v[i];
    int tar;cin>>tar;
    int idx = Nearest(v,n,tar);
    cout<<idx<<"\n";
    return 0;
}