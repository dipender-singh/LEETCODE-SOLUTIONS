// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution
{
public:

    void subsetsum(int i , vector<int> arr ,int N, vector<int> &ans , int sum){
        if(i==N){
            ans.push_back(sum);
            return;
        }
        sum = sum + arr[i]; // we have included the element
        subsetsum(i+1,arr,N,ans,sum); // made the function call
        sum = sum - arr[i];// we have explored all the options when we have included all the elements now we are moving from down to up and we see that we have taken a element then we have to explore that if we don't take that element what will be our sum
        subsetsum(i+1,arr,N,ans,sum);
    }

    vector<int> subsetSums(vector<int> arr, int N)
    {
        // Write Your Code here
    /*At every point i  have two options which are:-
    1.) Choose the element present at the ith Index.
    2.) Not to choose the element.
    */
        vector<int> ans;
        subsetsum(0,arr,N,ans,0);
        return ans;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0 ; i < N ; i++){
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr,N);
        sort(ans.begin(),ans.end());
        for(auto sum : ans){
            cout<< sum<<" ";
        }
        cout<<endl;
    }
    return 0;
}  // } Driver Code Ends