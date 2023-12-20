class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        //Brute Force
        //Recursion : I guess because here we have to minimize the Sum of the Money of the Chocolate i buy using money. 
        sort(prices.begin(),prices.end());
        if(money - (prices[0]+prices[1]) < 0){
            return money;
        }
        return money - (prices[0] + prices[1]);
    }
};