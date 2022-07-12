// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    public:
    int kthElement(int input1[], int input2[], int n, int m, int k)
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
        /*Now By Using again Merge Sort but without using an Extra Space
        int count = 0, i = 0, j = 0;
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
        TC IS O(MAX(M,N))+O(MIN(M,N)) IN THE WORST CASE
        SC IS O(1)
        */
        //Now by using the concept of Binary Search similar to Median of two sorted arrays
       if(n>m){
           return kthElement(input2,input1,m,n,k);
       }
       int l1 = 0 , l2 = 0 , r1 = 0 , r2 = 0;
       int low = max(0,k-m);
       int high = min(k,n);
       while(low<=high){
           int part_x = (low+high)/2;
           int part_y = k-part_x;
           
           if(part_x == 0){
               l1 = INT_MIN;
           }
           else{
               l1 = input1[part_x-1];
           }
           if(part_y==0){
               l2 = INT_MIN;
           }
           else{
               l2 = input2[part_y-1];
           }
           if(part_x == n){
               r1 = INT_MAX;
           }
           else{
               r1 = input1[part_x];
           }
           if(part_y == m){
               r2 = INT_MAX;
           }
           else{
               r2 = input2[part_y];
           }
           if(l1<=r2 and l2<=r1){
               return max(l1,l2);
           }
           else if(l1>r2){
               high = part_x-1;
           }
           else {
               low = part_x+1;
           }
       }
       return 0;
       //TC IS O(log(min(m,n)))
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