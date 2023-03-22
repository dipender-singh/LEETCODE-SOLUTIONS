class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        //Sub-arrays with elements as zero
        //Brute Force: Because after O(N^2) approach the solution is giving TLE.
        ios_base::sync_with_stdio(0);
        cin.tie(0);cout.tie(0);
        int n = nums.size()-1;
        long long ans = 0;
        int curr,next=0;
        /*
        for(int i = 0 ; i <= n ; i++){
            ans++;
        }
        if(ans==nums.size()){
            return ans
        }
        ans = 0;
        for(int i = 0 ; i <= n ; i++){ //O(N)
            if(nums[i]==0){
                next = i;
                while(next<=n and nums[next]==0){ //O(N)
                    ans++;
                    next++;
                }
            }
        }
        return ans;
        //Time Complexity : O(N*N)
        //Space Complexity : O(1)
        */
        int no_of_cons=0;
        for(int i = 0 ; i <= n ; i++){
            if(nums[i] == 0){
                no_of_cons++;
                ans = ans + no_of_cons;
            }
            else{
                no_of_cons=0;
            }
        }
        return ans;
    }
};