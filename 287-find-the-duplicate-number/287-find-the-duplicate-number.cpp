//https://www.youtube.com/watch?v=32Ll35mhWg0
//https://www.youtube.com/watch?v=pavdSf5f5pw (TO UNDERSTAND THE SOLUTION WATCH BOTH VIDEOS)
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);cout.tie(0);
        /*brute force
        map<int,int> mp;
        int ans=0;
        for(int i = 0 ; i < nums.size() ; i++){
            mp[nums[i]]++;
            if(mp[nums[i]]==2){
               ans = nums[i];
            }
        }
        return ans;
        */
        //two pointer or torotise and hare algo with slow and fast pointer slow moves one fast moves two postion
        int slow = nums[0];
        int fast = nums[0];
        //now we will keep on moving the slow and fast pointer untill and unless they point to the same element
        do{
            slow = nums[slow];
            fast = nums[nums[fast]];
        }while(slow!=fast);
        fast=nums[0];
        while(fast!=slow){
            slow=nums[slow];
            fast=nums[fast];
        }
        return fast;
    }
};