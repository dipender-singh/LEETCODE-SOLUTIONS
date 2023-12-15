class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        //Calculate the Out-Degree of each Node
        map<string,int>mp;
        //First Keep all the Nodes in the Graph
        for(int i = 0 ; i < paths.size() ; i++){
            for(auto it : paths[i]){
                mp[it] = 0;
            }
        }
        
        
        for(int i = 0 ; i < paths.size() ; i++){
            //First is the Parent and Second is the Child.
            mp[paths[i][0]]++;
        }
        for(auto it : mp){
            if(it.second == 0){
                return it.first;
            }
        }
        return "";
    }
};