// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Item{
    int value;
    int weight;
};


 // } Driver Code Ends
//class implemented
/*
struct Item{
    int value;
    int weight;
};
*/


class Solution
{
    public:
    
    static bool comp(Item a , Item b){
        double r1 = (double)a.value/(double)a.weight;
        double r2 = (double)b.value/(double)b.weight;
        return (r1 > r2);// return ture if no need to swap 
    }
    
    //Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        // Your code here
        // sort the array in descending order of their profit=value/weight
        sort(arr,arr+n,comp);
        double ans = 0.0;
        for(int i = 0 ; i < n ; i++){
            if(W==0){
                break;
            }
            else if(arr[i].weight <= W and W!=0){
                ans = ans + arr[i].value;
                W=W-arr[i].weight;
            }
            else if(arr[i].weight > W and W!=0){
                ans = ans + (arr[i].value/(double)arr[i].weight)*(double)W;
                W=0;
            }
        }
        return ans;
    }
        
};


// { Driver Code Starts.
int main()
{
	int t;
	//taking testcases
	cin>>t;
	cout<<setprecision(2)<<fixed;
	while(t--){
	    //size of array and weight
		int n, W;
		cin>>n>>W;
		
		Item arr[n];
		//value and weight of each item
		for(int i=0;i<n;i++){
			cin>>arr[i].value>>arr[i].weight;
		}
		
		//function call
		Solution ob;
		cout<<ob.fractionalKnapsack(W, arr, n)<<endl;
	}
    return 0;
}  // } Driver Code Ends