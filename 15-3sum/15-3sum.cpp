class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);cout.tie(0);
        vector<vector<int>> an;
        sort(nums.begin(),nums.end());
        for(int i = 0 ; i < (int)nums.size()-2 ; i++){ // for selecting a 
            if(i==0 || (i>0 && nums[i]!=nums[i-1] )){
                int lo = i+1,hi = (int)nums.size()-1,sum=0-nums[i];
                while(lo<hi){
                    if(nums[lo]+nums[hi]==sum){
                        vector<int> ans;
                        ans.push_back(nums[lo]);
                        ans.push_back(nums[hi]);
                        ans.push_back(nums[i]);
                        an.push_back(ans);
                        
                        while(lo < hi && nums[lo]==nums[lo+1]) lo++;
                        while(lo < hi && nums[hi]==nums[hi-1]) hi--;
                        lo++;
                        hi--;
                    }
                    else if(nums[lo]+nums[hi] < sum) lo++;
                    else if(nums[lo]+nums[hi] > sum) hi--; 
                }
            }
        }
        return an;
    }
};