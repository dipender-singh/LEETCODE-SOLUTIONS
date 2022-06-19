class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);cout.tie(0);
        /*Brute Force
        int final_ans = 1;
        int curr_ans = 1;
        if(nums.size()==0){
            return 0;
        }
        else{
            sort(nums.begin(),nums.end()); O(nlogn)
            int prev = nums[0];
            for(int i = 1 ; i < nums.size() ; i++){ O(n)
                if(nums[i]==prev){ // even if there are repeated elements they can still contribute to                                    // a sequence but they will not be taken into considerattion for                                      // the length of the longest sequence
                    continue;
                }
                else if(prev+1 == nums[i]){
                    curr_ans++;
                }
                else {
                    curr_ans = 1;
                }
                prev=nums[i];
                final_ans = max(final_ans, curr_ans);
            }
        }
        return final_ans;
        */
        // Optimal Approach can be to use a Hash-Map
        unordered_set < int > hashSet;
  for (int num: nums) {
    hashSet.insert(num);
  }

  int longestStreak = 0;

  for (int num: nums) {
    if (!hashSet.count(num - 1)) { // agar humra num hai 1 toh agar humara num-1 i.e. 0 agar woh                                          // present nahi hai toh iska matlab ek sequnce ka humare pass
                                   // statring point a gya hai toh ab hum uske sare next elements of 
                                   // the sequence find karenge
      int currentNum = num;
      int currentStreak = 1;

      while (hashSet.count(currentNum + 1)) {
        currentNum += 1;
        currentStreak += 1;
      }

      longestStreak = max(longestStreak, currentStreak);
    }
  }

  return longestStreak;
    }
};