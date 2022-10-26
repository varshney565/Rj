#include<iostream>
using namespace std;

bool binary_search(int *arr,int tar,int si,int ei){
    if(si > ei)
        return false;
    int mid = si+(ei-si)/2;
    if(arr[mid] > tar)
        return binary_search(arr,tar,si,mid-1);
    else if(arr[mid] < tar)
        return binary_search(arr,tar,mid+1,ei);
    else return true;
}

int main(){
    int n;
    cin>>n;
    int *arr = new int[n];
    for(int i = 0 ; i < n ; i++) cin>>arr[i];
    int tar;
    cin>>tar;
    if(binary_search(arr,tar,0,n-1))
        cout<<"Element Found\n";
    else
        cout<<"Element Not Found\n";
    return 0;
}