class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);cout.tie(0);
        vector<int> ans;
        int i = 0 , j = 0; 
        while(i<nums1.size() and j<nums2.size()){
            if(nums1[i]<=nums2[j]){
                ans.push_back(nums1[i]);
                i++;
            }
            else{
                ans.push_back(nums2[j]);
                j++;
            }
        }
        while(i<nums1.size()){
            ans.push_back(nums1[i]);
            i++;
        }
        while(j<nums2.size()){
            ans.push_back(nums2[j]);
            j++;
        }
        int x = ans.size();
        double result = 0;
        if(x%2!=0){
            int ind = x-1;
            result = (double) ans[(ind+1)/2];
        }
        else{
            int ind = x-1;
            result = (double) (ans[ind/2]+ans[(ind/2)+1])/(double) 2;
        }
        return result;
    }
};