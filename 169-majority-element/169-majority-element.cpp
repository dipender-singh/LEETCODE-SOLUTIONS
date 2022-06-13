class Solution {
public:
    int majorityElement(vector<int>& nums) {
        //brute
        map<int,int>mp;
        int n = nums.size();
        int ans=0;
        for(int i = 0 ; i < nums.size() ; i++){
            mp[nums[i]]++;
            if(mp[nums[i]]>n/2){
                ans=nums[i];
            }
        }
        return ans;
    }
};