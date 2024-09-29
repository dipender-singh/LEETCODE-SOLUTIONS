class Solution {
public:
    int singleNumber(vector<int>& nums) {
        //Linear Time and No Extra Space as well
        //Will use Bit Manipulation here
        //Well can't use sorting here. 
        //Expand the Property of XOR of 2 bit to 3 bits.
        int ans = 0;
        for(int i = 0 ; i < 32 ; i++){
            int count = 0 ;
            for(int j = 0 ; j < nums.size() ; j++){
                if(((1 << i) & nums[j]) == 0){
                    count++; //We are counting the Numbers of 0's.
                }
            }
            //Count%3 == 0 means that we are able to pair the 0's and means we are not able to put 1's in pair of 3, 
            //so here the i'th bit of the Answer Variable will be a 1. 
            if(count%3 == 0){
                ans = ans | (1 << i);
            }
        }
        return ans;
        //This is O(32*N) ~~ O(N).
    }
};