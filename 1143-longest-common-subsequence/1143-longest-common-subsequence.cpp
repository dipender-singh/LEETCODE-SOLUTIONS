class Solution {
public:
    /*
    int helper(int i,int j, string text1, string text2){
        //Termination Condition
        if(i>=text1.size() || j>=text2.size()){
            return 0;
        }
        if(text1[i] == text2[j]){ //When both the characters at which currently our pointer is
            return 1 + helper(i+1,j+1,text1,text2); 
        }
        else{ //This is the condition when our characters are different
            //To easily understand this particular condition just try and do a dry run over the case
            //text1 = abcdgh and text2 = aedf
            return max(helper(i+1,j,text1,text2),helper(i,j+1,text1,text2));    
        }
    }
    
    int longestCommonSubsequence(string text1, string text2) {
       //Brute Force
        ios_base::sync_with_stdio(0);
        cin.tie(0);cout.tie(0);
        return helper(0,0,text1,text2);
    }
    */
    /*
    int helper(int i , int j , vector<vector<int>>& dp, string text1, string text2){
        //If the answer already exists
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        if(i>=text1.size() || j>=text2.size()){
            return 0;
        }
        if(text1[i]==text2[j]){
            dp[i][j] = 1 + helper(i+1,j+1,dp,text1,text2);
            return dp[i][j];
        }
        else{
            dp[i][j] = max(helper(i,j+1,dp,text1,text2),helper(i+1,j,dp,text1,text2));
            return dp[i][j];
        }
    }
    
    //Memoization Solution
    int longestCommonSubsequence(string text1, string text2) {
       //Brute Force
        ios_base::sync_with_stdio(0);
        cin.tie(0);cout.tie(0);
        int m = text1.size();
        int n = text2.size();
        if(m==0 || n==0){
            return 0;
        }
        vector<vector<int>> dp(1001, vector<int> (1001,-1));
        return helper(0,0,dp,text1,text2);
    }
    */
    
    //Dynamic Programming
    int longestCommonSubsequence(string text1, string text2) {
       //Brute Force
        ios_base::sync_with_stdio(0);
        cin.tie(0);cout.tie(0);
        int m = text1.size();
        int n = text2.size();
        if(m==0 || n==0){
            return 0;
        }
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));
        dp[0][0] = 0;
        for(int i = 0 ; i <= m ; i++){
            dp[i][0] = 0;
        }
        for(int i = 0 ; i <= n ; i++){
            dp[0][i] = 0;
        }
        for(int i = 1 ; i <= m ; i++){
            for(int j = 1 ; j <= n ; j++){
                if(text1[i-1]==text2[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                }
                else{
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
            }
        }
        return dp[m][n];
    }
    
};