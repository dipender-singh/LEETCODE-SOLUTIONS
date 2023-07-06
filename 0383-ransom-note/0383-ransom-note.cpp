class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        //Brute Force
        int n = ransomNote.size();
        int m = magazine.size();
        //We have to Make magazine using the Letters present in the String ransomNote.
        map<char,int> mp;
        for(int i = 0 ; i < n ; i++){
            mp[ransomNote[i]]++;
        }
        for(int j = 0 ; j < m ; j++){
            if(mp.find(magazine[j])!=mp.end()){
                mp[magazine[j]]--;
                if(mp[magazine[j]]==0){
                 mp.erase(magazine[j]);   
                }
            }
        }
        return mp.empty();
    }
};