class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);cout.tie(0);
        int ans = 0;
        int n = strs[0].size();
        int x = 0;
        //Now i have to move on columns
        for(int i = 0 ; i < n ; i++){
            for(int j = 1 ; j < strs.size() ; j++){
                x = strs[j-1][i];
                if(strs[j][i]<x){
                    ans++;
                    break;
                }
            }
        }
        return ans;
    }
};