class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        //Now there are Three Cases: 
     /*  1. When there are No Zeroes, then every element will be (Product of all the Elements of the array)/(nums[i]). 
        2. When there is Only One Zero then the resultant array will contain all the elements to be Zero, except the Element which is Zero, Example : the nums {1,2,3,0} 
        Now for the Resultant array, when we are calculating the value for the element 1, then we will calcualte the product of all the elements except 1, then the product will be 2*3*0, which will ultimately be "ZERO". 
        3. When there are more than One Zero in the nums array, then all the elements will be zero, for example, the nums array {1,2,3,0,5,0}, then in the resultant array for the element at the Zero'th Index what will be the product of all the elements except the zeroth index element 2*3*0*5*0 = Zero, and for all the elements while calculating the Product of all the elements excluding that specific element we will always get the Product as ZERO, so when there is more than One Zero in the array, then all the elements will be Zero.*/
        //Brute Force Approach
        /*
       int n = nums.size();
       vector<int> ans(n,0);
        for(int i = 0; i < n; i++) {
            int pro = 1;
            for(int j = 0; j < n; j++) {
                if(i == j) continue;
                pro *= nums[j];
            }
            ans[i] = pro;
        }
        return ans;
        //Time and Space Complexity: Time is O(N*2) and Space is O(N)
        */
        //Better Approach
        int n = nums.size();
        vector<int> pre(n,0);
        vector<int> suff(n,0);
        pre[0] = 1;
        suff[n - 1] = 1;
        
        for(int i = 1; i < n; i++) {
            pre[i] = pre[i - 1] * nums[i - 1];
        }
        for(int i = n - 2; i >= 0; i--) {
            suff[i] = suff[i + 1] * nums[i + 1];
        }
        
        vector<int> ans(n,0);
        for(int i = 0; i < n; i++) {
            ans[i] = pre[i] * suff[i];
        }
        return ans;
        //Time Complexity : O(N*2)
    }
};