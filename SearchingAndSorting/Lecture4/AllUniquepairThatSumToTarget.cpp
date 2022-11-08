/**
 * find total number of pairs that are summing up to target.
*/

#include<bits/stdc++.h>
using namespace std;

int go(vector<int> &v,int n,int target){
    int ans = 0;
    sort(v.begin(),v.end());
    int i = 0,j = n-1;
    while(i < j){
        if(v[i] + v[j] == target){
            ans++;
            i++;
            j--;
            while(i < j && v[i] == v[i-1]){
                i++;
            }
            while(j > i && v[j] == v[j+1]){
                j--;
            }
        }else if(v[i]+v[j] > target){
            j--;
        }else{
            i++;
        }
    }
}

int main(){
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i = 0 ; i < n ; i++) cin>>v[i];
    int tar;cin>>tar;
    cout<<go(v,n,tar)<<"\n";
    return 0;
}