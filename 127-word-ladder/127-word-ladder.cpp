class Solution {
public:
     int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        //BFS is used to find the shortest path from a source to other vertices in an unweighted graph.
        ios_base::sync_with_stdio(0);
        cin.tie(0);cout.tie(0);
        //Very famous and Important Graph Question
        int ans = 1;
        int n = wordList.size();
        int ws = beginWord.size(); //Length of a word
        //Visited set of Words to indicate that we have visited certain words and we can't consider them again 
        //for our shortest sequence. For this we have created a set of strings named st.
        set<string> list;
        queue<string> q;
        for(auto it : wordList){
            list.insert(it);
        }
        q.push(beginWord);
        while(q.size()!=0){
            int x = q.size();
            for(int i = 0 ; i < x ; i++){
            string s = q.front();
            q.pop();
            list.erase(s); //Now we will delete particular string from the set so we can't explore it again
            if(s == endWord){ //When the given beginWord is equal to endWord
                return ans;
            }
            //Now what we will do is we will replace each character in current string with characters  
            //form a to z and will find that is there any string which is present in the list and we have not
            //considered it yet. If there exists such string we will add it to our queue and will mark it 
            //visited or considerd and add it to the set. We are using set because it's operations requires 
            //constant time complexity.
            for(int i = 0 ; i < ws ; i++){
                char ch = s[i];
            for(int j = 0 ; j < 26 ; j++){
                s[i]='a' + j;
                if(list.find(s)!=list.end()){
        //Newly generated string should exist in the given original wordlist  
                    q.push(s);
                    list.erase(s);
                }
            }
                s[i] = ch; //Now add the old character again which was replaced to search for different new  
                           //strings which exist in the given wordList.
            }
        }
            ++ans;
        }
        return 0;
    }
};