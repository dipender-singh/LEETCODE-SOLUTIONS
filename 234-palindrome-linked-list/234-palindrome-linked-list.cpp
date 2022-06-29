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
      STRUCTURE
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
    // TC IS O(N)+O(N) IF THE LINKED LIST IS PALINDROME ELSE WE WILL RETURN FALSE ANYWHERE IN BW OF 
    // OUR STACK
    // SC IS O(N) FOR THE STACK
    */
    // OPTIMAL APPROACH USING TWO POINTER WHEN FAST POINTER REACHES TO END SLOW IS AT THE MIDDLE SO, 
    // WHILE WE TRAVERSE OUR TWO POINTERS SIDE BY SIDE WE WILL KEEP ON REVERSING OUR LIST BEHIND OUR 
    // SLOW POINTER. JUST AFTER OUR FAST REACHES TO END WE WILL TRAVERSE OUR SLOW AND WE WILL TRAVERSE 
    // THE LINKED LIST WHICH WE HAVE REVERSED AND THEN WE WILL KEEP ON MATCHING THE VALUES
    bool isPalindrome(ListNode* head){
        ios_base::sync_with_stdio(0);
        cin.tie(0);cout.tie(0);
        ListNode* slow = head;
        ListNode* fast = head;
        //ALL WE HAVE TO DO IS JUST REVERSE THE LINKED LIST BEHIND THE SLOW POINTER
        ListNode* p=NULL;
        ListNode* temp = head;
        if(head==NULL){
            return true;
        }
        while(fast!=NULL and fast->next!=NULL){ // TC HERE IS O(N/2)
            fast=fast->next->next;
            temp=slow;
            slow=slow->next;
            temp->next=p;
            p=temp;
        }
        if(fast!=NULL and fast->next==NULL){ // THIS IS THE CASE WHEN WE HAVE AN ODD SIZE LINKED LIST 
            //AND WHEN FAST->NEXT IS EQUAL TO NULL OUR SLOW POINTER WILL BE AT THE MIDDLE ELEMENT SO 
            // WE JUST HAVE TO MOVE THE SLOW POINTER TO IT'S NEXT POSITION   
            slow=slow->next;
        }
        while(slow!=NULL and p!=NULL){ // TC HERE IS AGAIN O(N/2)
            if(slow->val!=p->val){
                return false;
            }
            slow=slow->next;
            p=p->next;
        }
        return true;
        // SO TOTAL TC IS O(N/2) + O(N/2)
        // AND SC IS O(1)
    }
};