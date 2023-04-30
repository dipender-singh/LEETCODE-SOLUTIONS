class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0){
            return false;
        }
        //Just Reverse the Integer and Compare both the Numbers by converting them to strings
        string rev = to_string(x);
        reverse(rev.begin(), rev.end());
        return to_string(x) == rev;
    }
};