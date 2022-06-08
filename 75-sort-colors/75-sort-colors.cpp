class Solution {
public:
    void sortColors(vector<int>& nums) {
        //BASIC SORT AN ARRAY OF 0'S 1'S AND 2'S
        //brute force
         ios_base::sync_with_stdio(0);
         cin.tie(0);
         cout.tie(0);
        /*
        if(nums.size()>1){
         int l = 0 ;
         int h =nums.size()-1;
         int n = nums.size();
         vector<int> ans(n,4);
        for(int i = 0 ; i <= n-1 ;i++){
            if(nums[i]==0 and l <= h){
                ans[l]=0;
                l++;
            }
            if(nums[i]==2 and l <= h){
                ans[h]=2;
                h--;
            }
        }
        for(int i = 0 ; i < nums.size() ; i++){
            if(ans[i]==4){
                ans[i]=1;
            }
        }
        nums=ans; 
        }
        */
        int l = 0;
        int h=nums.size()-1;
        int mid = l;
        while(mid<=h){
            if(nums[mid]==0){
                swap(nums[mid],nums[l]);
                l++;
                mid++;
            }
            else if(nums[mid]==2){
                swap(nums[mid],nums[h]);
                h--;
                
            }
           else if(nums[mid]==1){
                mid++;
            }
        }
    }
};