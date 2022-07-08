class Solution {
public:
    
    bool palindrome(int start ,int end, string s){
        while(start<=end){
            if(s[start]!=s[end]){
                return false;
            }
            start++;
            end--;
        }
        return true;
    }
    
    void substring(int ind ,string s,vector<vector<string>>& res, vector<string>& path){
        //Base Case
        if(ind == s.size()){
            res.push_back(path);
            return;
        }
        for(int i = ind ; i < s.size() ; i++){
            if(palindrome(ind,i,s)){
                path.push_back(s.substr(ind,i-ind+1));  // substr(position,length) so for postion we will take 
                                                       //the ind value and for the length of the substring, we 
                                                      // will i to iterate from a given value of 
                                                     //ind to the rest of the length of the string so thats why 
                                                    //lenght of the substring = i - ind + 1
                substring(i+1,s,res,path); // from every index we will check for all the other values of 'i' if 
                                           // we can get a substring or not.
                path.pop_back();
            }
        }
    }
    
    vector<vector<string>> partition(string s) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);cout.tie(0);
        vector<vector<string>> res;
        vector<string> path;
        substring(0,s,res,path);
        return res;
    }
};