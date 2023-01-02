class Solution {
public:
    bool detectCapitalUse(string word) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);cout.tie(0);
        int n=word.length();
        if(n==1)return true;
        int capitals=0, smalls=0;
        for(int i=0;i<word.size();i++){
            if(word[i]>='A' && word[i]<='Z'){
                capitals++;
            }
            else{
                smalls++;
            }
        }
        if(capitals==word.size() || smalls==word.size()){
            return true;
        }
        else if(word[0]>='A' && word[0]<='Z' && smalls==word.size()-1){
            return true;
        }
        else{
            return false;
        }
    }
};