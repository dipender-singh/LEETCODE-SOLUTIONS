class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        /*
        Every consecutive pair of integers have opposite signs.
        For all integers with the same sign, the order in which they were present in nums is preserved.
        The rearranged array begins with a positive integer.
        */
        vector<int> pos;
        vector<int> neg;
        for(int i = 0 ; i < nums.size() ; i++){
            if(nums[i] < 0){
                neg.push_back(nums[i]);
            }
            if(nums[i]>=0){
                pos.push_back(nums[i]);
            }
        }
        int i = 0;
        vector<int> ans;
        for(int i = 0 ; i < pos.size() ; i++){
            ans.push_back(pos[i]);
            ans.push_back(neg[i]);
        }
        return ans;
    }
};