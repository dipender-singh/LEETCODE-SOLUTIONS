class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);cout.tie(0);
        map<int,int> mp;
        int ans=0;
        for(int i = 0 ; i < nums.size() ; i++){
            mp[nums[i]]++;
            if(mp[nums[i]]==2){
               ans = nums[i];
            }
        }
        return ans;
    }
};