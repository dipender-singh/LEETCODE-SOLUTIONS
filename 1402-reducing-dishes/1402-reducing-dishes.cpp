class Solution {
public:
    /*
    int helper(int i, int n, int t, vector<int>& sat){
        if(i == n){
            return 0;
        }
        return max(helper(i+1,n,t,sat),helper(i+1,n,t+1,sat)+sat[i]*t);
    }
    
    int maxSatisfaction(vector<int>& satisfaction) {
        //Now in order to maximize the Like-time coefficient, we will make the dish first that is having the smaller 
        //satisfaction level, so we will sort the satisfaction array first. 
        sort(satisfaction.begin(),satisfaction.end());
        //Now we will simply use recursion here because at step we will have two choices either to pick up the dish 
        //or to leave that dish, and for counting the like time coefficient of the dish we will multiply it with time 
        //and satisfaction[i]. and time is basically the number of that dish. 
        int n = satisfaction.size();4
        return helper(0,n,1,satisfaction);
    }
    */
    
    int helper(int i , int t, int n, vector<int>& s, vector<vector<int>>& dp){
        if(dp[i][t]!=-1){
            return dp[i][t];
        }
        if(i == n){
            return 0;
        }
        dp[i][t] = max(helper(i+1,t,n,s,dp),helper(i+1,t+1,n,s,dp)+s[i]*(t+1));
        return dp[i][t];
    }
    
    int maxSatisfaction(vector<int>& s) {
        sort(s.begin(),s.end());
        int n = s.size();
        vector<vector<int>> dp(n+1, vector<int> (n+1,-1));
        return helper(0,0,n,s,dp);
    }
};