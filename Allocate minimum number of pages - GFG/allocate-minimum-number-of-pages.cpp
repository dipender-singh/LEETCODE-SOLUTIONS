// { Driver Code Starts
// Initial template for C++

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template in C++

class Solution 
{
    
    bool isvalid(int A[],int N, int M, int mid){
        int s = 1;
        int sum = 0;
        for(int i = 0 ; i < N ; i++){
            sum += A[i];
            if(sum>mid){
                s++;
                sum=A[i];
                if(s>M){
                    return false;
                }
            }
        }
        return true;
    }
    
    public:
    int findPages(int A[], int N, int M) 
    {
        if(N<M){
            return -1;
        }
        sort(A,A+N);
    //Minimum number of pages that a person will read will proabably be the book with max pages
    int low = A[N-1];
    //high will be the sum of all the pages of all the books
    int high = 0;
    for(int i = 0 ; i < N ; i++){
        high+=A[i];
    } 
    int res = -1; // if we cant allocate books according to the given statement
    while(low<=high){
        int mid = low + ((high - low)/2);
        if(isvalid(A,N,M,mid)==true){ // if we can allocate the mid number of pages to the given number of students then we will update the result variable
            res= mid;
            high = mid - 1; // we will try to find a more smaller number of pages which can be allocated to the given no. of students
        }
        else{
            low = mid + 1;
        }
    }
    return res;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int A[n];
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        int m;
        cin>>m;
        Solution ob;
        cout << ob.findPages(A, n, m) << endl;
    }
    return 0;
}
  // } Driver Code Ends