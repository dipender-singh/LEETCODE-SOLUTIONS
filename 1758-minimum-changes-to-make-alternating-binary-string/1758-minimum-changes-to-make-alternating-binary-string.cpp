class Solution {
public:
    int minOperations(string s) {
        //Hint 1: Think how the Final String will look like.
        //Hint 2: If the String starts from 0 then at every odd position we are gonna have a string with odd at every odd index. And if the String starts with a 1 then at every odd position we are gonna have a even element. 
        //Hint 3: We are gonna try with both ways first we are gonna start with the Index 0 having a 0. And then we are gonna start with the Index 0 having a 1. Then we will see which will take minimum number of steps.
        int ans1 = 0;
        int ans2 = 0;
        //I am assuming that this for loop is for when the string starts with 1.
        for(int i = 0 ; i < s.size() ; i++){
            if(s[i] == '1' and i%2 == 1){
                ans1++;
            }
            else if(s[i] == '0' and i%2 == 0){
                ans1++;
            }
        }
        for(int i = 0 ; i < s.size() ; i++){
            if(s[i] == '0' and i%2 == 1){
                ans2++;
            }
            else if(s[i] == '1' and i%2 == 0){
                ans2++;
            }
        }
        return min(ans1,ans2);
    }
};