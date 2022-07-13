class Solution {
public:
    bool isValid(string s) {
       //Brute Force
        ios_base::sync_with_stdio(0);
        cin.tie(0);cout.tie(0);
        stack<char> st;
        if(s.size()==1){
            return false;
        }
        //We will run a for loop to see all the brackets
        for(int i = 0 ; i < s.size() ; i++){
            if(s[i]=='(' || s[i]=='{' || s[i]=='['){//If we encounter a open bracket push it into the stack
                 st.push(s[i]);
            }
            else{
    if((s[i]==')' and st.size()==0 ) || (s[i]==']' and st.size()==0 ) || (s[i]=='}' and st.size()==0 )){
                    return false;
                }
                char ch = st.top();
                if( (ch=='(' and s[i]==')' ) || (ch=='[' and s[i]==']' ) || (ch=='{' and s[i]=='}' ) ){
                    st.pop();
                    continue;
                }
                else if(s[i]!=ch){
                    return false;
                }
            }
        }
        if(st.size()==0){
        return true;
        }
        return false;
    }
};