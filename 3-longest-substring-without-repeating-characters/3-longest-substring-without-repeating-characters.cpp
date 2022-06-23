class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);cout.tie(0);
      /* OPTIMIZED
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
  */
       // we will take a freq array that will store the index of a particular character of the string
        vector < int > mpp(256, -1);

      int left = 0, right = 0;
      int n = s.size();
      int len = 0;
      while (right < n) {
        if (mpp[s[right]] != -1) left = max(mpp[s[right]] + 1, left); // if cond. is true this is exe.
          
          mpp[s[right]] = right;// if not then this is exe.
          
          len = max(len, right - left + 1);
          right++;
      }
      return len;
    }
};
