class Solution {
public:
    
    using lli = long long int;
    
    lli check(lli mid, lli x){
        if(mid * mid >= x){
            return 1;
        }
        return 0;
    }
    
    int mySqrt(int x) {
        
        //We are gonna solve this Problem now
        //First we will do a bit of a dry run to see the flow
        //then we will decidr which algo or Ds we will use here
        //after writing code do a bit of dry run of tc and check for edge cases as well
        //then after all this try to find the Time and Space complexity 
        //Got it 
        lli low = 0, high = x;
        lli ans = -1;
        while(low <= high){
            lli mid = (low) + (high - low)/2;
            if(mid * mid == x){
                return mid;
            }
            else if(check(mid,x) == 1){
                ans = mid;
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }
        if(ans*ans>x){
            return ans-1;
        }
        return ans;
    }
};