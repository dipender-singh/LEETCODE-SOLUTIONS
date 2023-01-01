class Solution {
public:
    bool wordPattern(string pattern, string s) {
        //brute
        ios_base::sync_with_stdio(0);
        cin.tie(0);cout.tie(0);
         vector<string> words;
    string temp = "";
    for(int i=0;i<s.length();i++){
        if(s[i] == ' '){
            words.push_back(temp);
            temp = "";
        }
        else{
            temp.push_back(s[i]);
        }
    }
    words.push_back(temp);
    if(pattern.length()<words.size() || pattern.length()>words.size()){
        return false;
    }
    unordered_map<char,string> m;
    for(int i=0;i<pattern.size();i++){
        if(m.find(pattern[i])==m.end()){
            m[pattern[i]] = words[i];
        }
        else if(m[pattern[i]] != words[i]){
            return false;
        }
    }
    unordered_set<string> set;
    for(auto it:m){
        set.insert(it.second);
    }
    if(m.size()!=set.size()) return false;
    return true;

}
};