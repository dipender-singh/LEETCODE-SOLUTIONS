class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        /*
        //Brute Force Approach: Simply using the Two Loop's. 
        vector<int> ans;
        int n = numbers.size();
        for(int i = 0 ; i < n-1 ; i++){
            for(int j = i + 1 ; j < n ; j++){
                if(numbers[i]+numbers[j] == target){
                    ans.push_back(i+1);
                    ans.push_back(j+1);
                    break;
                }
                if(ans.size() == 2){
                break;
                }
            }
        }
        return ans;
        //Time Complexity: O(N^2)
        //Space Complexity: O(1), we are using the Vector because we have to return the answer of our's in that Vector.
        //Point to Note, since after solving a couple of questions based on the Two Pointer Approach, i have find out that where ever we are able to solve the Question using 2-For Loops, then for sure we can solve that question using the Two Pointer Approach. 
        */
        //Better Approach: 
        int n = numbers.size();
        int low = 0;
        int high = numbers.size()-1;
        vector<int> ans;
        while(low<high){
            if(numbers[low] + numbers[high] > target){
                high --;
            }
            else if(numbers[low] + numbers[high] < target){
                low++;
            }
            else if(numbers[low] + numbers[high] == target){
                ans.push_back(low+1);
                ans.push_back(high+1);
                break;
            }
        }
        return ans;
    }
};