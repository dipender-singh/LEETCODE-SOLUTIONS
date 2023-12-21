class Solution {
public:
    int strStr(string haystack, string needle) {
        if(haystack.size() < needle.size()){
            return -1;
        }
        int first_index = 0;
        int j = 0;
        for(int i = 0 ; i < haystack.size() ; i++){
            j = 0;
            int index = i;
            if(haystack[i] == needle[j]){
                first_index = i;
                int size = 0;
                while(haystack[index] == needle[j] and size < needle.size()){
                    j++;
                    index++;
                    size++;
                }
                if(size == needle.size()){
                    return first_index;
                }
            }
        }
        return -1;
    }
};