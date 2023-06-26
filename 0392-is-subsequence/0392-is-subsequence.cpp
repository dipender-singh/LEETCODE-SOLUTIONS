class Solution {
public:
    bool isSubsequence(string s, string t) {
        //Brute Force: Now here in this Brute Froce solution we are not able to keep a track of the Order of the Elements.
        //Now we have to keep a track of the order of the elements as well. 
        
        //This is also the longest common subsequence kinda variation.
        
        //1. Brute Force
        int j = 0; // For index of str1 (or subsequence
 
    // Traverse str2 and str1, and
    // compare current character
    // of str2 with first unmatched char
    // of str1, if matched
    // then move ahead in str1
    for (int i = 0; i < t.length() && j < s.length(); i++)
        if (s[j] == t[i])
            j++;
 
    // If all characters of str1 were found in str2
    return (j == s.length());

    }
};