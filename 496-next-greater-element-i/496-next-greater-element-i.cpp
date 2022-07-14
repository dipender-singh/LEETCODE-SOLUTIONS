class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);cout.tie(0);
        //BRUTE FORCE
        vector<int> ans;
        for(int i = 0 ; i < nums1.size() ; i++){// We will iterate for every element in nums1
            bool flag = false;
            for(int j = 0 ; j < nums2.size() ; j++){
                if(nums1[i]==nums2[j]){
                    flag = true; // Means we have found the ith element in the nums2 array
                }
                if(flag==true and nums2[j]>nums1[i]){
                    flag=false; // Setting it false means that we have found the element and we have stored it
                    ans.push_back(nums2[j]);
                    break;
                }
            }
            if(flag==true){
                ans.push_back(-1); // Flag is still true means that we did find the ith element in nums2 but we 
                                   // were not able to find it's next greator element in the nums2 array
            }
        }
        return ans;
        //TC IS O(M*N)
        //SC IS O(M) WHEN FOR EVERY ELEMENT OF M WE GET A NEXT GREATOR IN N SIZE ARRAY
    }
};