//Geeks for Geeks ---> count such subarrays.
//Leetcode 525 ---> Find the maximum length subarray.


//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution{
  public:
    //Function to count subarrays with 1s and 0s.
    long long int countSubarrWithEqualZeroAndOne(int arr[], int n)
    {
        for(int i = 0 ; i < n ; i++){
            if(!arr[i])
                arr[i] = -1;
        }
        //now the task is to find the total number of subarrays with sum equals to 0;
        map<int,int> cnt;
        int ans = 0;
        int sum = 0;
        for(int i = 0 ; i < n ; i++){
            sum += arr[i];
            if(sum == 0)
                ans += 1;
            if(cnt.find(sum) != cnt.end()){
                ans += cnt[sum];
            }
            cnt[sum]++;
        }
        return ans;
        
        /**
         * the time complexity of this approach is O(nlogn) and space complexity is O(n)
         * */
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	int n,i;
	cin>>n;
	int arr[n];
	for(i=0;i<n;i++)
	cin>>arr[i];
	Solution obj;
	cout<< obj.countSubarrWithEqualZeroAndOne(arr, n)<<"\n";
	}
	return 0;
}

// } Driver Code Ends
