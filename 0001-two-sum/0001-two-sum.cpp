class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> ans;
        //Brute Froce : Time Comlexity is O(N*2) and Space Complexity is O(N)
        /*
        for(int i = 0 ; i < n-1 ; i++){
            for(int j = i+1 ; j < n ; j++){
                if(nums[i]+nums[j] == target){
                    ans.push_back(i);
                    ans.push_back(j);
                    break;
                }
            }
        }
        return ans;
        */
        //Better Solution: 
        //Now why we are using Hash-Map think it like this we are basically mapping two variables to a single target
        unordered_map<int,int> mp;
        for(int i = 0 ; i < n ; i++){
            int curr = target - nums[i];
            if(mp.empty()){
                mp[nums[i]] = i;
            }
            else if(mp.find(curr)!=mp.end()){
                ans.push_back(mp[curr]);
                ans.push_back(i);
                return ans;
            }
            mp[nums[i]] = i;
        }
        return ans;
    }
};