class Solution {
public:
    int maxArea(vector<int>& height) {
        //Brute Force:
        /*
        int ans = INT_MIN;
        int curr = 0; 
        int n = height.size();
        for(int i = 0 ; i < n-1 ; i++){
            for(int j = i+1 ; j < n ; j++){
                //Water = Length(Min. of the Two Bars) * Breadth(index "j" - index "i")
                curr = (min(height[i],height[j])) * (j - i);
                ans = max(ans,curr);
            }
        }
        return ans;
        //Time Complexity: O(N^2)
        //Space Complexity: O(1)
        */
        
        //Better Approach:
        //Now the maximum water is basically the maximum area. And the maximum area depends upon two factors length and the 
        //breadth.
        
        //Gonna Try using the Two-Pointer Approach:
        int n = height.size();
        int i = 0;
        int j = n-1;
        int ans = INT_MIN;
        int curr = 0;
        while(i<j){
            curr = min(height[i],height[j]) * (j-i);
            ans = max(ans,curr);
            if(height[i] < height[j]){
                i++;
            }
            else {
                j--;
            }
        }
        return ans;
    }
};