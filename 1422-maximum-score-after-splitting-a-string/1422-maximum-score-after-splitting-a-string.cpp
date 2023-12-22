class Solution {
public:
    
    int helper2(int i, int j, string s){
        int ans = 0;
        while(i <= j){
            if(s[i] == '1'){
                ans++;
            }
            i++;
        }
        return ans;
    }
    
    int helper1(int i, int j, string s){
        //We will calcualte the Number of Zeroes in the Left
        int ans = 0;
        while(i<=j){
            if(s[i] == '0'){
                ans++;
            }
            i++;
        }
        return ans;
    }
    
    int maxScore(string s) {
        int n = s.size();
        int maxi = 0;
        for(int i = 1 ; i < n ; i++){
            int left = helper1(0,i-1,s);
            int right = helper2(i,n-1,s);
            maxi = max(maxi,left+right);
        }
        return maxi;
    }
};