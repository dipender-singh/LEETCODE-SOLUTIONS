/*https://leetcode.com/problems/maximum-subarray/discuss/1595195/C%2B%2BPython-7-Simple-Solutions-w-Explanation-or-Brute-Force-%2B-DP-%2B-Kadane-%2B-Divide-and-Conquer*/
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
         ios_base::sync_with_stdio(0);
         cin.tie(0);cout.tie(0);
        /* normal brute force
        int sum = INT_MIN;
        for(int i = 0 ; i < nums.size() ; i++){
            for(int j = i ; j < nums.size() ; j++){
                int s = 0 ;
                for(int k = i ; k <= j ; k++){
                    s=s+nums[k];
                    sum=max(s,sum);
                }
            }
        }
        return sum;
        */
        //KADANES ALGO
        int max_total = nums[0];
        int max_ab_tak = nums[0];
        for(int i = 1 ; i < nums.size() ; i++ ){
            if((max_ab_tak+nums[i]) > nums[i]){
                max_ab_tak = max_ab_tak+nums[i];
            }
            else {
                max_ab_tak = nums[i];
            }
            if(max_ab_tak > max_total){
                max_total = max_ab_tak;
            }
        }
        return max_total;
    }
};