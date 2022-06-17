class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);cout.tie(0);
        int final_ans = 1;
        int curr_ans = 1;
        if(nums.size()==0){
            return 0;
        }
        else{
            sort(nums.begin(),nums.end());
            int prev = nums[0];
            for(int i = 1 ; i < nums.size() ; i++){
                if(nums[i]==prev){
                    continue;
                }
                else if(prev+1 == nums[i]){
                    curr_ans++;
                }
                else {
                    curr_ans = 1;
                }
                prev=nums[i];
                final_ans = max(final_ans, curr_ans);
            }
        }
        return final_ans;
        /*
        if(nums.size() == 0 ){
            return 0;
        }
        
        sort(nums.begin(),nums.end());
        
        int ans = 1;
        int prev = nums[0];
        int cur = 1;
        
        for(int i = 1;i < nums.size();i++){
            if(nums[i] == prev+1){
                cur++;
            }
            else if(nums[i] == prev){
                cur = 1;
            }
            prev = nums[i];
            ans = max(ans, cur);
        }
        return ans;
        */
    }
};