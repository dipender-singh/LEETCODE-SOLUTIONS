class Solution {
public:
    using lli = long long int;
    
    lli check(vector<int>& nums, lli x){
        lli boundary = INT_MIN;
        if(x+1 >= nums.size()){
          return 1;  
        }
        else if(nums[x] > nums[x+1]){
            return 1;
        }
        return 0;
    }
    
    int findPeakElement(vector<int>& nums) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);cout.tie(0);
        //Going to use Binary Search, as this is kind of a Bitonic Array
        //I have to find the Element in the Given array, so it is Binary Search on Index. 
        //And main game is of the Check Function, we have to write such a check function such that we get a Montonic 
        //Array. 
        
        lli low = 0;
        lli high = nums.size()-1;
        lli ans = -1;
        while(low <= high){
            lli mid = (low) + (high - low)/2;
            if(check(nums,mid) == 1){
                ans = mid;
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return ans;
    }
};