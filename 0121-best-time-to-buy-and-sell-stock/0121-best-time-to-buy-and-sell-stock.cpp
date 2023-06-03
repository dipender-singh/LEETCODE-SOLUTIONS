class Solution {
public:
    int maxProfit(vector<int>& prices) {
        /*Brute Force Approach : If we will follow the approach of Finding the Maximum and Minimum element over the whole array and then calculate the maximum profit, so there might be a case that we will be getting a minimum element after the greatest element which disrupt the order of selecting the days according to the question. So either what we shall do is while selecting the Greatest and Smaller Price in the array we should also keep on caluclating the Profit as well.
        int n = prices.size();
        int l = INT_MAX;
        int p = 0;
        for(int i = 0 ; i < n ; i++){
            l = min(l,prices[i]);
            for(int j = i+1 ; j < n ; j++){
                p = max(p,prices[j]-l);
            }
        }
        return p;
        Time Complexity: O(N*2) and Space Complexity: O(1)
        */
        //Better Approach: Using One For Loop
        int n = prices.size();
        int l = INT_MAX;
        int p = 0;
        for(int i = 0 ; i < n - 1 ; i++){
            l = min(l,prices[i]);
            p = max(p,prices[i+1]-l);
        }
        return p;
    }
};