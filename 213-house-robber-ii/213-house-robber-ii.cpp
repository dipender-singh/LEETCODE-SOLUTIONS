/*
Now at each house we have two options:-
            
            1.) First option is that we can loot the current house and then go for the third house from the  
            current house.
            2.) Second option is that we will not loot the current house and then we will go to the next   
            house and then decide should we loot that house or not.
            
            So in total if i say, we have two options, to loot the current house and then go for the third  
            house from the current house and then the second option is that we can skip the current house. 
            
            ****Now if i have robbed the first index house then i can't go and rob the last index house.****
            
            So now what we can do is consider two cases one in which we consider the houses from 0 to n-2  
            indices and in another case we consider the houses from index 1 to n-1 since we can't consider  
            first and last house together.
*/


class Solution {
public:
    
    int roby(vector<int> &nums)
    {
           //Other Name of this Question is:- Maximum sum of non-adjacent elements
        
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

    
    int rob(vector<int>& nums) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    vector<int> first;
    vector<int> second;
    int n = nums.size();
    if(n==1){
        return nums[0];
    }
    for(int i = 0 ; i < n ; i++){
        if( i != 0 ) first.push_back(nums[i]);
        if( i != n-1 ) second.push_back(nums[i]);
    }
    int ans1 = roby(first);
    int ans2 = roby(second);
    return max(ans1,ans2);
    }
};