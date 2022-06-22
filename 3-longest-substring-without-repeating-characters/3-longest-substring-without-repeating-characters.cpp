class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);cout.tie(0);
        //optimized
        if(s.size()==0 || s.size()==1){
            return s.size();
        }
      int maxans = INT_MIN;
  unordered_set < int > set;
  int l = 0;
  for (int r = 0; r < s.length(); r++) // outer loop for traversing the string
  {
    if (set.find(s[r]) != set.end()) //if duplicate element is found
    {
      while (l < r && set.find(s[r]) != set.end()) {
        set.erase(s[l]);
        l++;
      }
    }
    set.insert(s[r]);
    maxans = max(maxans, r - l + 1);
  }
  return maxans;
    }
};
