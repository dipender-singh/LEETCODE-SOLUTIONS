class Solution
{
    public:
        /*Memoization Code:-
        int helper(int c, int n, vector<int> &nums, vector<int> &dp)
        {
           	//Base Case
            if (c == n)
            {
                dp[c] = nums[c];
                return nums[c];
            }
            if (c > n)
            {
                return 0;
            }
            if (dp[c] != -1)
            {
                return dp[c];
            }
            /*Now left and right can be used to describe the two scenarios:-
            1.) We can loot the current the house then leave the next adjacent house and go for the house at                 the third position from the current house.
            2.) We can leave the current house and can go for the next adjacent house and then decide to loot                 the next adjacent house.*/
            /*int left = nums[c] + helper(c + 2, n, nums, dp);	//Looted the current house
            int right = helper(c + 1, n, nums, dp);	//Not Looted the current house
            dp[c] = max(left, right);	//Return the max profit out of both the scenarios
// dp[c] represents the maximum profit from '0' to the index 'c'.
            return dp[c];
        }

    int rob(vector<int> &nums)
    {
       	//Other Name of this Question is:- Maximum sum of non-adjacent elements
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        int ans = 0;
        int n = nums.size() - 1;
        vector<int> dp(nums.size(), -1);
       	//Now at every house i have two options either i can loot that particular house or i can leave the 
       	//current house and go towards the next house.
        ans = helper(0, n, nums, dp);
        return ans;
    }
    */
    /*Dynamic Programming Code:- 
    int rob(vector<int> &nums)
    {
       	//Other Name of this Question is:- Maximum sum of non-adjacent elements
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        int ans = 0;
        int n = nums.size(); //This is the last index
        vector<int> dp(nums.size(),-1);
        dp[0] = nums[0];
        if(n==1){
            return nums[0];
        }
        dp[1] = max(nums[0],nums[1]);
        for(int i = 2 ; i < n ; i++){
            dp[i] = max((dp[i-2] + nums[i]) , dp[i-1]); 
//Each Index of the DP Vector represents the maximum profit we have obatined till now from index 0 to a 
//particular index without picking no adjacent elements from the sequence of indices [0.....c].
        }
        return dp[n-1];
    }
    //Time and Space Complexity:- TC is O(N) and Space is O(N).
    //Can Further do some Space Optimization and can be done without using the DP Vector
    */
    //Memory Optimized Solution
    int rob(vector<int> &nums)
    {
       	//Other Name of this Question is:- Maximum sum of non-adjacent elements
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        int prev = nums[0];
        if(nums.size()==1){
            return nums[0];
        }
        int prev2 = 0;
        int curr = 0;
        for(int i = 1 ; i < nums.size() ; i++){
            int take = nums[i];
            if(i>1) take = take + prev2;
            
            int non_take = prev;
            
            curr = max(take,non_take); 
            prev2 = prev;
            prev = curr; 
        }
        return prev;
    }
};