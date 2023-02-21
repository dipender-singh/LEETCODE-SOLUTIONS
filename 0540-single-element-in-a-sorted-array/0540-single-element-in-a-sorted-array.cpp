class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        //Brute Force
        //Now we have to find the Element which is occuring twice
        //Brute Force will be using the O(N) Space Complexity
        ios_base::sync_with_stdio(0);
        cin.tie(0);cout.tie(0);
        unordered_map<int,int> mp;
        int n= nums.size();
        for(int i = 0 ; i < n ; i++){
            if(mp.find(nums[i])==mp.end()){
                mp[nums[i]] = 1;
            }
            else {
                mp[nums[i]]++;
            }
        }
        int ans = 0;
        for(int i = 0 ; i < n ; i++){
            if(mp[nums[i]] == 1){
                ans = nums[i];
            }
        }
        return ans;
    }
};