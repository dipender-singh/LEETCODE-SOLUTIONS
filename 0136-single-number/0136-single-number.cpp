class Solution {
public:
    int singleNumber(vector<int>& nums) {
        //Uisng Bit Manipluation
        int ans = 0;
        for(int i = 0 ; i < nums.size() ; i++){
            ans = ans ^ nums[i];
        }
        return ans;
    }
};