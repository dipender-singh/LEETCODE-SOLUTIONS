class Solution {
public:
    
    void subset(int i , vector<int>& nums, vector<int>& ans, set<vector<int>>& use){
        use.insert(ans); // sabse pehle ans null hai to woh add ho gya
        if(i==nums.size()){
            return;
        }
        ans.push_back(nums[i]);
        subset(i+1,nums,ans,use);
        ans.pop_back();
        subset(i+1,nums,ans,use);
        return;
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);cout.tie(0);
        //BRUTE FORCE
        sort(nums.begin(),nums.end());
        vector<int> ans;
        vector<vector<int>> finl;
        set<vector<int>> use;
        subset(0,nums,ans,use);
        for(auto it:use){
            finl.push_back(it);
        }
        return finl;
    }
};