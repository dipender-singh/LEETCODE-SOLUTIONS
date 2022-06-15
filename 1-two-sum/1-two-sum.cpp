class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        //brute force
        ios_base::sync_with_stdio(0);
        cin.tie(0);cout.tie(0);
        set<int> s;
        vector<int> ans;
        for(int i = 0 ; i < nums.size() ; i++){
            for(int j = i+1 ; j < nums.size() ; j++){
                if(nums[i]+nums[j]==target){
                   s.insert(i);
                   s.insert(j);
                    //break;
                }
            }
        }
        copy(s.begin(), s.end(), inserter(ans, ans.begin()));
        return ans;
    }
};