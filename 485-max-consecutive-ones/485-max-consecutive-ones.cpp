class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);cout.tie(0);
        int max_count = 0;
        int ans = 0;
        for(int i = 0 ; i < nums.size() ; i++){
            if(nums[i]==1){
                ans++;
            }
            else if(nums[i]==0){
                ans=0;
            }
            max_count=max(ans,max_count);
        }
        return max_count;
    }
};