/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    /*
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        //BRUTE FORCE
        ios_base::sync_with_stdio(0);
        cin.tie(0);cout.tie(0);
        unordered_map<ListNode* , int>mp;
        ListNode *temp = NULL;
        while(headA!=NULL){ //O(M) FOR THE WORST CASE
            mp[headA]++;
            headA=headA->next;
        }
        while(headB!=NULL){ //O(N) FOR THE WORST CASE
            if(mp[headB]==1){
                temp = headB;
                break;
            }
            headB=headB->next;
        }
        return temp;
    }
    // TC:- O(M)+O(N);
    // SC:- In my solution it is equal to the lenght of LIST1, it can further be optimized to 
    // O(min(M,N)) for this first we will have to find the list1 and list2 length then out of both 
    // which is minimum that size can be used to create a map
    */
    /* OPTIMAL APPROACH
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB){
        ios_base::sync_with_stdio(0);
        cin.tie(0);cout.tie(0);
        ListNode* a = headA;
        ListNode* b = headB;
        ListNode* temp = NULL;
        int as = 0 , bs = 0;
        USING THE DIFFERENCE BETWEEN THE LENGTH'S
        Step 1-> Find the length of both Linked-Lists and take their difference 'd'
        Step 2-> Move the larger node forward by 'd' steps
        Step 3-> Now the starting point of both linkedlists are equidistant from intersection ,so move 
        both pointers together untill the intersection is found.
        TC->O(m+n) , SC->O(1)
        while(a!=NULL){
            as++;
            a=a->next;
        }
        while(b!=NULL){
            bs++;
            b=b->next;
        }
        a=headA;
        b=headB;
        int diff = 0;
        if(as<bs){
            diff = bs-as;
            while(diff!=0){
                b=b->next;
                diff--;
            }
        }
        else{
            diff = as-bs;
            while(diff!=0){
                a=a->next;
                diff--;
            }
        }
        while(a!=b and a!=NULL and b!=NULL){
            a=a->next;
            b=b->next;
        }
        if(a!=NULL){
            return a;
        }
        return temp;
    }
    */
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB){
        ios_base::sync_with_stdio(0);
        cin.tie(0);cout.tie(0);
        /* USING TWO POINTER*/
        ListNode* a = headA;
        ListNode* b = headB;
        while(a!=b){
            if(a==NULL){
                a=headB;
            }
            else{
                a = a -> next;
            }
            if(b==NULL){
                b=headA;
            }
            else{
                b = b -> next;
            }
        }
        return a;
    }
};
