class Solution {
public:
    int maxProduct(vector<int>& nums) {
        //Brute Force ----> After think of Two Pointer Kind of Solution 
        int ans = INT_MIN;
        for(int i = 0 ; i < nums.size() ; i++){
            for(int j = 0 ; j < nums.size() ; j++){
                if(i != j){
                    ans = max(ans,((nums[i]-1)*(nums[j]-1)));
                }
            }
        }
        return ans; 
    }
};