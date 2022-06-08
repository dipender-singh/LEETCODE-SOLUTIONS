class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        //https://leetcode.com/problems/merge-sorted-array/discuss/600243/C%2B%2B-solution-           //O(m%2Bn)-solution-with-detailed-explanation.
        ios_base::sync_with_stdio(0);
          cin.tie(0);cout.tie(0);
      int i=m-1,j=n-1,k=m+n-1;
        while(i>=0&&j>=0)
        {
            if(nums1[i]>nums2[j])
            {
                nums1[k]=nums1[i];
                i--;
                k--;
            }
            else
            {
                nums1[k]=nums2[j];
                j--;
                k--;
            }
        }
        while(j>=0)
            nums1[k--]=nums2[j--];
    }
};