class Solution {
public:
    int majorityElement(vector<int>& nums) {
        /*brute but using o(n) extra space and o(n) tc
        //hashing
        ios_base::sync_with_stdio(0);
        cin.tie(0);cout.tie(0);
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
        */
        // sorting
        ios_base::sync_with_stdio(0);
        cin.tie(0);cout.tie(0);
        sort(nums.begin(),nums.end());
        return nums[nums.size()/2];
    }
};