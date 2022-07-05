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
    	//Comparator function to sort the trains on the basis of their departure time
    	vector<pair<int,int>> times;
    	for(int i = 0 ; i < n ; i++){
    	    times.push_back({arr[i],dep[i]});
    	}
    	sort(times.begin(),times.end());
    	priority_queue<int, vector<int>, greater<int>> pq; // this is min priority queue
    	int np = 1;
    	int siz = 1;
    	pq.push(times[0].second);
    	for(int i = 1 ; i < n ; i++){
    	    if(times[i].first > pq.top()){
    	        pq.pop();
    	        pq.push(times[i].second);
    	    }
    	    else{
    	        pq.push(times[i].second);
    	    }
    	    siz = pq.size(); 
    	    np=max(np,siz);
    	}
    	return np;
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