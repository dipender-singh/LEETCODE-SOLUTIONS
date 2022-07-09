class Solution {
public:
    int search(vector<int>& nums, int target) {
        //Brute Force
        ios_base::sync_with_stdio(0);
        cin.tie(0);cout.tie(0);
        int ans = -1;
        for(int i = 0 ; i < nums.size() ; i++){
            if(nums[i]==target){
                ans = i;
            }
        }
        return ans;
    }
};