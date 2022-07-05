// { Driver Code Starts
// Program to find minimum number of platforms
// required on a railway station
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    public:
    //Function to find the minimum number of platforms required at the
    //railway station such that no train waits.
    int findPlatform(int arr[], int dep[], int n)
    {
    	// Your code here
    	sort(arr,arr+n); // Sort the Arrival
    	sort(dep,dep+n); // Sort the Departure
    	int i = 1, j = 0, max_p = 1, current_p = 1;
    	while(i < n && j < n){
    	    if(arr[i] > dep[j]){
    	        current_p--;
    	        j++;
    	    }
    	    else if(arr[i] <= dep[j]){
    	        current_p++;
    	        i++;
    	    }
    	    if(current_p > max_p){
    	        max_p = current_p;
    	    }
    	}
    	return max_p;
    }
};


// { Driver Code Starts.
// Driver code
int main()
{
    int t;
    cin>>t;
    while(t--) 
    {
        int n;
        cin>>n;
        int arr[n];
        int dep[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        for(int j=0;j<n;j++){
            cin>>dep[j];
        }
        Solution ob;
        cout <<ob.findPlatform(arr, dep, n)<<endl;
    } 
   return 0;
}  // } Driver Code Ends