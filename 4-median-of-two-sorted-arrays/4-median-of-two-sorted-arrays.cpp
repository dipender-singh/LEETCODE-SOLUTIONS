class Solution {
public:
    double findMedianSortedArrays(vector<int>& input1, vector<int>& input2) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);cout.tie(0);
        /*Brute Force
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
        //TC IS O(MAX(M,N))
        //SC IS O(M+N)
        */
        //By using the concept of Binary Search
        //We will be using that array which has the smallest lenght as our primary array
        if (input1.size() > input2.size()) {
            return findMedianSortedArrays(input2, input1);
        }
        int x = input1.size();
        int y = input2.size();

        int low = 0;
        int high = x;
        while (low <= high) {
            int partitionX = (low + high)/2;
            int partitionY = (x + y + 1)/2 - partitionX;

            //if partitionX is 0 it means nothing is there on left side. Use -INF for maxLeftX
            //if partitionX is length of input then there is nothing on right side. Use +INF for minRightX
            int maxLeftX = (partitionX == 0) ? INT_MIN : input1[partitionX - 1];
            int minRightX = (partitionX == x) ? INT_MAX : input1[partitionX];

            int maxLeftY = (partitionY == 0) ? INT_MIN : input2[partitionY - 1];
            int minRightY = (partitionY == y) ? INT_MAX : input2[partitionY];

            if (maxLeftX <= minRightY && maxLeftY <= minRightX) {
                //We have partitioned array at correct place
                // Now get max of left elements and min of right elements to get the median in case of even length combined array size
                // or get max of left for odd length combined array size.
                if ((x + y) % 2 == 0) {
                    return ((double)max(maxLeftX, maxLeftY) + min(minRightX, minRightY))/2;
                } else {
                    return (double)max(maxLeftX, maxLeftY);
                }
            } else if (maxLeftX > minRightY) { //we are too far on right side for partitionX. Go on left side.
                high = partitionX - 1;
            } else { //we are too far on left side for partitionX. Go on right side.
                low = partitionX + 1;
            }
        }

        //Only we we can come here is if input arrays were not sorted. Throw in that scenario.
        return 0;
    }
};