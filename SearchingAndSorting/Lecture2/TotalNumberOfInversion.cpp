//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp>
#include <functional> // for less
using namespace __gnu_pbds;


typedef tree<long long, null_type, less_equal<long long>, rb_tree_tag,
             tree_order_statistics_node_update>
    ordered_set;
class Solution{
  public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    long long int inversionCount(long long arr[], long long n)
    {
        /**
         * brute-force-approach : 
         * 
         * just run two loops.
         * and find total number of elements such that i < j and a[i] > a[j]
         * 
         * complexity : O(n*n)
         * space      : O(1)
        **/
        
        
        
        
        /**
         * Optimised Approach 1 : 
         * 
         * use merge-sort
         * complexity : O(NlogN)
         * space      : O(1)
         */
         
         
         /**
          * optimised Approach 2 : 
          * using binary-search : 
          * How ??
          * 
          * when i am at the ith index just find the total number of elements that are greater then the ith element
          * in the set,and add the count to the answer.
          * 
          * using pbds
          * O(nlogn time)
          * O(n) space
         */
         
         ordered_set s;
         long long ans = 0;
         for(int i = 0 ; i < n ; i++){
             int order = s.order_of_key(arr[i]+1);
             ans += s.size()-order;
             s.insert(arr[i]);
         }
         return ans;
    }

};

//{ Driver Code Starts.

int main() {
    
    long long T;
    cin >> T;
    
    while(T--){
        long long N;
        cin >> N;
        
        long long A[N];
        for(long long i = 0;i<N;i++){
            cin >> A[i];
        }
        Solution obj;
        cout << obj.inversionCount(A,N) << endl;
    }
    
    return 0;
}

// } Driver Code Ends