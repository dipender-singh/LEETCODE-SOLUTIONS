class Solution {
public:
    int lengthOfLastWord(string s) {
        int ans = 0;
        int n = s.size();
        for(int i = 0 ; i < n ; i++){
            if(s[i] != 32){
                int start = i;
                int end = i;
                while(s[end]!=32 and end < s.size()){
                    end++;
                }
                //Just gonna check that have we reached the end of the String or not. 
                if(end == s.size()){
                    return (end - start);
                }
                ans = (end - start);
                i = end;
            }
        }
        return ans;
    }
};