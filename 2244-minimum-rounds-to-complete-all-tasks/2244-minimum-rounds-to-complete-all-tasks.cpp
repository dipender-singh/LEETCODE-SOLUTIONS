class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        //Brute
        ios_base::sync_with_stdio(0);
        cin.tie(0);cout.tie(0);
        int ans = 0;
        //Using Hashing
        unordered_map<int,int> mp;
        for(int i = 0 ; i < tasks.size() ; i++){
            mp[tasks[i]]++;
        }
        //Now calculating if a particular task has freq less than 2
        for(auto it : mp){
            if(it.second<=1){
                return -1;
            }
        }
        for(auto it : mp){
            if(it.second == 2){
                ans = ans + 1;
            }
            else if((it.second % 3 == 0)){
                //If the freq is divisible by 2 and 3 both then we will divide by 3 only
                ans = ans + it.second/3;
            }
            else{
                    ans = ans + it.second/3 + 1;
            }
        }
        return ans;
    }
};