class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        //Brute Force
        //Now i have to remove from the num's only;
        vector<int> ans;
        for(int i = 0 ; i < nums.size() ; i++){
            if(nums[i] != val){
                ans.push_back(nums[i]);
            }
        }
        nums = {};
        for(int i  = 0 ; i < ans.size() ; i++){
            nums.push_back(ans[i]);
        }
        val = {};
        return nums.size();
    }
};