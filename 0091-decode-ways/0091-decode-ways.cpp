class Solution {
public:
    
    int helper(int i, string s, vector<int> &dp){
        if(i == s.size()){
            dp[i] = 1;
            return 1;
        }
        if(i > s.size()){
            return 0;
        }
        if(s[i] == '0'){
            dp[i] = 0;
            return 0;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        int take = 0;
        take = helper(i+1,s,dp);
        //In order to make a Two Digit Number first one can be 1 or 2, but the second needs to be between 0 to 6. 
        if(((s[i] == '1' || s[i] == '2' and s[i+1]<= '6') ) and i+2 <= s.size()){
            take+= helper(i+2,s,dp);
        }
        dp[i] = take;
        return take;
    }
    
    int numDecodings(string s) {
        //Zero as a Single can not exist and 0 as a starting digit of a number can also not exist.
        vector<int> dp(s.size()+1,-1);
        return helper(0,s,dp);
    }
};