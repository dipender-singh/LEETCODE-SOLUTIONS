class Solution {
public:
    bool isSubsequence(string s1, string s2) {
        //Dynamic Programming
        int n = s1.size();
        int m = s2.size();
        vector<vector<string>> dp(n+1,vector<string>(m+1,""));

	for (int i = n - 1; i >= 0; i--) {
        for (int j = m - 1; j >= 0; j--) {
            if (s1[i] == s2[j]) {
                dp[i][j] = s1[i] + dp[i + 1][j + 1];
            } else {
                dp[i][j] = (dp[i + 1][j].size() >= dp[i][j + 1].size()) ? dp[i + 1][j] : dp[i][j + 1];
            }
        }
    }
        string ans = dp[0][0];
        if(ans.size()!=n) return false;
        for(int i = 0 ; i < ans.size() ; i++){
            if(ans[i]!=s1[i]) return false;
        }
        return true;
    }
};