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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);cout.tie(0);
        int a = 0 , carry = 0 , ans1 = 0;
        ListNode* dummy = new ListNode;
        ListNode* temp = dummy;
        while(l1!=NULL and l2!=NULL){
            a = l1->val + l2->val + carry;
            ans1 = a % 10;
            carry = a / 10;
            ListNode* node = new ListNode(ans1); // will createa new node
            temp->next=node;// temp pointer point to dummy now it temp next will point to node
            temp=temp->next;// temp will now be pointing to the newly created node
            l1=l1->next;
            l2=l2->next;
        }
        while(l1!=NULL){
            a = l1->val + carry;
            ans1 = a % 10;
            carry = a / 10;
            ListNode* node = new ListNode(ans1); // will createa new node
            temp->next=node;// temp pointer point to dummy now it temp next will point to node
            temp=temp->next;// temp will now be pointing to the newly created node
            l1=l1->next;
            //l2=l2->next;
        }
        while(l2!=NULL){
            a = l2->val + carry;
            ans1 = a % 10;
            carry = a / 10;
            ListNode* node = new ListNode(ans1); // will createa new node
            temp->next=node;// temp pointer point to dummy now it temp next will point to node
            temp=temp->next;// temp will now be pointing to the newly created node
            l2=l2->next;
        }
        //Now check that my carry is greator than equal to 1 or not
        if(carry>=1){
            ListNode* node = new ListNode(carry); // will create a new node with value eq to carry
            temp->next=node;
            temp=temp->next;
        }
        return dummy->next;
    }
};