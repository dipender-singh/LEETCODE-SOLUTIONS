class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<long long> st; //As integer will not be able to store the calculation of large integers
        ios_base::sync_with_stdio(0);
        cin.tie(0);cout.tie(0);
        for(auto it : tokens){
            if(it=="+"||it=="-"||it=="*"||it=="/"){
                long long b = st.top(); st.pop(); // As stack is long long so, it is self explanatory 
                long long a = st.top(); st.pop();
                if(it == "+") a = (a+b);
                if(it == "-") a = (a-b);
                if(it == "*") a = (a*b);
                if(it == "/") a = (a/b);
                st.push(a);
            }
            else{
                st.push(stoll(it));//stol is used with long int and stoll is used with long long int
            }
        }
        return (int)st.top();//Type conversion of float float to int datatype
        }
    //TC IS O(N) [WHERE N IS THE SIZE OF THE STRING]
    //SC IS O(N) [WHERE N IS THE SIZE OF THE STRING]
};