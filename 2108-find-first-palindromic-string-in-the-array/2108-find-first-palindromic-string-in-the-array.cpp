class Solution {
public:
    
    bool helper(string curr){
        int i = 0;
        int j = curr.size()-1;
        while(i<=j){
            if(curr[i]!=curr[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    
    string firstPalindrome(vector<string>& words) {
        //Brute 
        bool ans = false;
        for(auto it : words){
            ans = helper(it);
            if(ans == true){
                return it;
            }
        }    
        return "";
    }
};