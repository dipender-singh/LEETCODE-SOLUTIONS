class Solution {
public:
    bool isSubsequence(string s, string t) {
        //Now the Problem says to use the Two-Pointer approach, now what we are goona do is that, we will keep one pointer on the starting of the String "s" and the other Pointer on the starting of the String "t".
        int i = 0, count = 0;
        for(int j = 0 ; i < s.size() , j < t.size() ; j++){
            //Now we will only move ahead when we have encountered an character of String S in the String T.
            if(s[i] == t[j]){
                count++;
                i++;
            }
        }
        if(count == s.size()){
            return true;
        }
        return false;
    }
};