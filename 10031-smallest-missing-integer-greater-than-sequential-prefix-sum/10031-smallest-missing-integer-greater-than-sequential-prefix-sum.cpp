class Solution {
public:
    int missingInteger(vector<int>& arr) {
        vector<int> ans;
        int sum = arr[0];
        for(int i = 1 ; i < arr.size() ; i++){
            if(arr[i] == arr[i-1]+1){
                sum = sum +arr[i];
            }
            else{
                //Here we break the Loop because only the prefix consisting only of nums[0] is sequential.
                break;
            }
        } 
        //If sum value does not exist in the array
        sort(arr.begin(),arr.end());
        for(int i = 0 ; i < arr.size() ; i++){
            if(sum == arr[i]){
                sum++;
            }
        }
        return sum; 
    }
};