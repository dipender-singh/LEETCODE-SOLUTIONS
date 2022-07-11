// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    public:
    int kthElement(int arr1[], int arr2[], int n, int m, int k)
    {
        /*Perform Merge sort to store the elements in a vector this is Brute Force
        vector<int> ans; // SC IS O(MAX(M,N))
        int i = 0 , j = 0; 
        if(arr1[0]<=arr2[0]){
            ans.push_back(arr1[0]);
            i++;
        }
        else{
            ans.push_back(arr2[0]);
            j++;
        }
        while(i<n and j<m){ // TC IS O(MIN(N,M))
            if(arr1[i]<=arr2[j]){
                ans.push_back(arr1[i]);
            i++;
            }
            else{
            ans.push_back(arr2[j]);
            j++;
        }
        }
        if(i<n){ // TC IS O(MAX(N,M)) - O(MIN(N,M))
            while(i<n){
            ans.push_back(arr1[i]);
            i++;
            }
        }
        else if(j<m){
            while(j<m){
            ans.push_back(arr2[j]);
            j++;
            }
        }
        return ans[k-1];
        TC IS O()
        */
        //Now By Using again Merge Sort but without using and Extra Space
           int count = 0, i = 0, j = 0;
 
    // Keep taking smaller of the current
    // elements of two sorted arrays and
    // keep incrementing k
    while(i < n && j < m)
    {
        if(arr1[i] < arr2[j])
        {
            count++;
            if(k == count)
                return arr1[i];
            i++;
        }
        else
        {
            count++;
            if(k == count)
                return arr2[j];
            j++;
        }
    }
 
    // If array B[] is completely traversed
    while(i < n)
    {
        count++;
        if(k == count)
            return arr1[i];
        i++;
    }
 
    // If array A[] is completely traversed
    while(j < m)
    {
        count++;
        if(k == count)
            return arr2[j];
        j++;
    }
    }
};

// { Driver Code Starts.
 
// Driver code
int main()
{
	int t;
	cin>>t;
	while(t--){
		int n,m,k;
		cin>>n>>m>>k;
		int arr1[n],arr2[m];
		for(int i=0;i<n;i++)
			cin>>arr1[i];
		for(int i=0;i<m;i++)
			cin>>arr2[i];
		
		Solution ob;
        cout << ob.kthElement(arr1, arr2, n, m, k)<<endl;
	}
    return 0;
}  // } Driver Code Ends