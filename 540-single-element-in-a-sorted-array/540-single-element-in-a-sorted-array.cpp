class Solution {
public:
    // HINT VIDEO: https://www.youtube.com/watch?v=PzszoiY5XMQ&list=PLgUwDviBIf0p4ozDR_kJJkONnb1wdx2Ma&index=65
    int singleNonDuplicate(vector<int>& nums) {
        //Brute Force can be using Hash-Map or Frequency Array and another can be using XOR
        // Optimized
        ios_base::sync_with_stdio(0);
        cin.tie(0);cout.tie(0);
        int low = 0;
        int high = nums.size()-2;
        while(low<=high){
            int mid = low + ((high - low)/2);
            if(mid%2==0){
                if(nums[mid]==nums[mid+1]){
                 low=mid+1;   
                }
                else{
                 high = mid-1;
                }
            }
            else{
                if(nums[mid]==nums[mid+1]){
                 high = mid-1;
                }
                else{
                 low=mid+1;
                }
            }
        }
        return nums[low];
    }
};