class Solution {
public:
    int largestRectangleArea(vector<int>& arr) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);cout.tie(0);
        /*Brute Force
        int n = heights.size();
        int maxa=0;
        for(int i = 0 ; i < n ; i++){
            int minh=INT_MAX;
            for(int j = i ; j < n ; j++){
                minh=min(minh,heights[j]);
                maxa=max(maxa,minh*(j-i+1));
            }
        }
        return maxa;
        */
//Now lets say we are at a random bar which is at index-4 of height 5 and we will move toward the left of that   
//bar, now we will stop when we will get a bar whose height is less than this bar of height 5. So we can say 
//that we have found the next smaller element than 5 in the left part (in general we have to find the next 
//smaller on the left of a particular bar)
//Code for the NEXT SMALLER ON THE LEFT (NSL)
//Now in Example 1 if we have to find the NSL then for the bar of height 2 we will take a pseudo index which 
//will be -1 and it's height will be 0 (we are considering it as floor or ground with height 0)
        int n = arr.size();
        stack<pair<int,int>> nsl;
        vector<int> left;
        stack<pair<int,int>> nsr;
        vector<int> right;
        int psi = n;
        for(int i = 0 ; i < n ; i++){
            if(nsl.size()==0){
                left.push_back(-1);
            }
            else if(nsl.size()!=0 and nsl.top().first < arr[i]){
                left.push_back(nsl.top().second);
            }
            else if(nsl.size()!=0 and nsl.top().first >= arr[i]){
                while(nsl.size()!=0 and nsl.top().first >= arr[i]){
                    nsl.pop();
                }
                if(nsl.size()==0){
                left.push_back(-1);
            }
                else {
                     left.push_back(nsl.top().second);
                }
            }
            nsl.push({arr[i],i});
        }
        for(int i = n-1 ; i >= 0 ; i--){
             if(nsr.size()==0){
                right.push_back(psi);
            }
            else if(nsr.size()!=0 and nsr.top().first < arr[i]){
                right.push_back(nsr.top().second);
            }
            else if(nsr.size()!=0 and nsr.top().first >= arr[i]){
                while(nsr.size()!=0 and nsr.top().first >= arr[i]){
                    nsr.pop();
                }
                if(nsr.size()==0){
                right.push_back(psi);
            }
                else {
                     right.push_back(nsr.top().second);
                }
            }
            nsr.push({arr[i],i});
        }
        reverse(right.begin(),right.end());
        vector<int> width;
        vector<int> area;
        int ans = 0;
        for(int i = 0 ; i < n ; i++){
            width.push_back(right[i]-left[i]-1);
        }
        for(int i = 0 ; i < n ; i++){
            area.push_back(arr[i]*width[i]);
        }
        for(int i = 0 ; i < n ; i++){
            ans= max(ans,area[i]);
        }
        return ans;
    }
};