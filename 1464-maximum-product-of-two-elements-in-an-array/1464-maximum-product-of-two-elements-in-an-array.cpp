class Solution {
public:
    int maxProduct(vector<int>& nums) {
        //First Sort and then use the Last Two items
        sort(nums.begin(),nums.end());
        int n = nums.size();
        return (nums[n-1]-1)*(nums[n-2]-1);
    }
};