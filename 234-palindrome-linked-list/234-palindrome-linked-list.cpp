/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    /*BRUTE FORCE USING A VECTOR
    bool isPalindrome(ListNode* head) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);cout.tie(0);
        if(head==NULL) {
            return false;
        }
        if(head->next==NULL){
            return true;
        }
        vector<int> ans; //SC IS O(N)
        ListNode* temp = head;
        int size = 0;
        while(temp!=NULL){ // TC IS O(N)
            ans.push_back(temp->val);
            size++;
            temp=temp->next;
        }
        int mid = size/2;
        if(size % 2 == 0){ // When the List is of Even Size
            for(int i = mid-1 , j = mid ; i>=0 , j < size ; i-- , j++){//O(N/2)
                if(ans[i]!=ans[j]){
                    return false;
                }
            }
        }
        if(size%2!=0){    // // When the List is of Odd Size
            for(int i = mid-1 , j = mid+1 ; i>=0 , j < size ; i-- , j++){//O(N/2)
                if(ans[i]!=ans[j]){
                    return false;
                }
            }
        }
        return true;
        //TC IS O(N)+O(N/2)
        //SC IS O(N)
        */
      /*APPROACH 2 USING STACK
      NOW WHERE-EVER WE OBSERVE TERMS LIKE REVERSE OR PALINDROME THEN STACK IS THE BEST AVAILABE DATA 
      STRUCTURE*/
       bool isPalindrome(ListNode* head){
           ios_base::sync_with_stdio(0);
           cin.tie(0);cout.tie(0);
           ListNode* temp = head;
           stack<int> st;
           while(temp!=NULL){
               st.push(temp->val);
               temp=temp->next;
           }
           temp=head;
           while(temp!=NULL){
             if(temp->val!=st.top()){
                   return false;
               }
               temp=temp->next;
               st.pop();
           }
           return true;
       }
};