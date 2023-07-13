class Solution {
public:
    string simplifyPath(string path) {
        //Now again
        stack<string> st;
        string ans;
        for(int i = 0 ; i < path.size() ; i++){
            if(path[i] == '/'){
                continue;
            }
            string temp;
            
            while(i < path.size() and path[i]!='/'){
                temp.push_back(path[i]);
                i++;
            }
            
            if(temp == "."){
                continue;
            }
            
            else if(temp == ".."){
                if(st.size()!=0){
                    st.pop();
                }
            }
            else {
                st.push(temp);
            }
        }
        
        if(st.size() == 0){
            return "/";
        }
        
        while(st.size()!=0){
            string s = st.top();
            ans.insert(0, "/" + s);
            st.pop();
        }
        return ans;
    }
};