class Solution {
public:
    // BRUTE FORCE USING RECURSION
   /* TC:- O(2^(N+M))
    int calculate(int i , int j, int r , int c){
        if( i >= r || j >= c ){ // we have crossed the specified boundaries
            return 0;
        }
        if(i==r-1 || c==j-1){ // we have reached the final destination 
            return 1;
        }
        int ans1=0,ans2=0;
         ans1 = calculate(i+1,j,r,c); //TC: O(2^N)
         ans2 = calculate(i,j+1,r,c); //TC: O(2^M)
         return ans1+ans2;
    }
    
    int uniquePaths(int m, int n) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);cout.tie(0);
        int ans=0;
        ans = calculate(0,0,m,n);
        return ans;
    }
    */
    
    int memoization(vector<vector<int>> &ans , int i , int j , int m, int n){
        
        if(ans[i][j]!=0){
            return ans[i][j];
        }
        if(i==m-1 || j == n-1){
            return 1;
        }
        int ans1=0;
        int ans2=0;
        ans1 = memoization(ans,i+1,j,m,n);
        ans2 = memoization(ans,i,j+1,m,n);
        ans[i][j]=ans1+ans2;
        return ans[i][j];
    }
    
    int uniquePaths(int m, int n){
        ios_base::sync_with_stdio(0);
        cin.tie(0);cout.tie(0);  
        //DP:- SAVING THE VALUES IN A MATRIX
        vector<vector<int>> ans(m, vector<int> (n,0));
        int a = memoization(ans,0,0,m,n);
        return a;
        }
};