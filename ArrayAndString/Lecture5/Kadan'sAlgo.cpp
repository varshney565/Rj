/**
 * Previous class note : 
 * 
 * Maximum length subarray with sum equals k won't work for neagitive elements.
 * [-3,-2,-1,1,2,3,4] target = 6;
 */

#include<bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) x.begin(),x.end()
#define pi pair<int,int>
#define ff first
#define ss second

//Maximum subarray sum.
//Kadan's Algo.

void solve(){
   //Taking input part....
   int n;
   cin>>n;
   vector<int> nums(n);
   for(int i = 0 ; i < n ; i++){
    cin>>nums[i];
   }





   //Kadan's Algorithem....
   int csi = 0,gsi = 0,gei = 0;
   int gsum = (int)-1e9,csum = 0;
   for(int i = 0 ; i < n ; i++){
    //it will give me the smallest window.
    if(csum + nums[i] <= nums[i]){
        csi = i;
    }

    if(csum > gsum){
        gsum = csum;
        gsi = csi;
        gei = i;
    }
   }
   cout<<gsum<<"\n";
}

signed main()
{
    #ifndef ONLINE_JUDGE
        freopen("../../IO/input.txt","r",stdin);
        freopen("../../IO/output.txt","w",stdout);
        freopen("../../IO/error.txt", "w", stderr);
    #endif

    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    cerr<<"time taken : "<<(float)clock()/CLOCKS_PER_SEC<<" secs"<<"\n";
    return 0;
}

