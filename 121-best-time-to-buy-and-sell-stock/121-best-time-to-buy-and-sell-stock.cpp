class Solution {
public:
    int maxProfit(vector<int>& prices) {
        /*BRUTE FORCE: THIS TAKES O(N^2)
        int n=prices.size();
        if(prices.size()==0 || prices.size()==1){
            return 0;
        }
        int curr;
        int ans=0;
        int min=INT_MAX;
        int max;
        for(int i = 0 ; i < n ; i++){
            if(min > prices[i]){
                min=prices[i];
            }
            for(int j = i+1 ; j < n ; j++){
                curr = prices[j] - min;
                if(curr > ans){
                    ans=curr;
                }
            }
        }
        return ans;
        */
        //THIS TAKES O(N)
        int maxp=0;
        int minp=INT_MAX;
        for(int i=0;i<prices.size();i++){
            minp = min(minp,prices[i]);
            maxp = max(maxp,prices[i]-minp);
        }
        return maxp;
    }
};