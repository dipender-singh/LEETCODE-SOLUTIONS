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
        vector<int> dp(n + 1, -1);
       	//Now at every house i have two options either i can loot that particular house or i can leave the 
       	//current house and go towards the next house.
        ans = helper(0, n, nums, dp);
        return ans;
    }
    */
    //Dynamic Programming Code:- 
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
        }
        return dp[n-1];
    }
};