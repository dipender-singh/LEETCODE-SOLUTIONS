class Solution {
public:
    int majorityElement(vector<int>& nums) {
        /*hashing used ans sc is o(n) and tc is o(n) 
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
        /* sorting is used space is o(1) and tc is o(nlogn)
        ios_base::sync_with_stdio(0);
        cin.tie(0);cout.tie(0);
        sort(nums.begin(),nums.end());
        return nums[nums.size()/2];
        */
        ios_base::sync_with_stdio(0);
        cin.tie(0);cout.tie(0);
        int count = 0, ele = 0;
        for(int i = 0 ; i < nums.size() ; i++){
            if(count == 0){
                ele = nums[i];
            }
            if(nums[i]==ele){
                count++;
            }
            else{
                count--;
            }
        }
        return ele;
    }
};