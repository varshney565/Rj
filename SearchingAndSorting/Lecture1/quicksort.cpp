#include<bits/stdc++.h>
using namespace std;

int partition(vector<int> &v,int si,int en,int pivotInd){
    swap(v[pivotInd],v[en]);
    int pivot = v[en];
    int i = -1;
    int j = 0;
    while(j <= en){
        if(v[j] <= pivot){
            i++;
            swap(v[i],v[j]);
        }
        j++;
    }
    return i;
}

void quickSort(vector<int> &v,int si,int en){
    if(si > en) return;
    int pivotInd = si+(rand()%(en-si+1));
    int idx = partition(v,si,en,pivotInd);
    quickSort(v,si,idx-1);
    quickSort(v,idx+1,en);
}

int main(){
    int n;cin>>n;
    vector<int> v(n);
    for(int i = 0 ; i < n ; i++) cin>>v[i];
    quickSort(v,0,n-1);
    for(int i = 0 ; i < n ; i++) cout<<v[i]<<" ";
    cout<<"\n";
    return 0;
}