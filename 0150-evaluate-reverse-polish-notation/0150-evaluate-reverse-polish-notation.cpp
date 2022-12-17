class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<long long> st;
        ios_base::sync_with_stdio(0);
        cin.tie(0);cout.tie(0);
        for(auto& it : tokens){
            if(it=="+"||it=="-"||it=="*"||it=="/"){
                long long b = st.top(); st.pop();
                long long a = st.top(); st.pop();
                if(it == "+") a = (a+b);
                if(it == "-") a = (a-b);
                if(it == "*") a = (a*b);
                if(it == "/") a = (a/b);
                st.push(a);
            }
            else{
                st.push(stoll(it));
            }
        }
        return (int)st.top();
        }
};