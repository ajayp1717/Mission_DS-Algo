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
    ListNode* partition(ListNode* head, int x) {
        
        ListNode* smallerHead=new ListNode(0);
        ListNode* smaller=smallerHead;
        ListNode* greaterEqualHead=new ListNode(0);
        ListNode* greaterEqual=greaterEqualHead;

        ListNode* curr=head;
        while(curr){
            if(curr->val < x){
                smaller->next=curr;
                smaller=smaller->next;
            }
            else{
                greaterEqual->next=curr;
                greaterEqual=greaterEqual->next;
            }
            curr=curr->next;  
        }
        //Join two partitions
        smaller->next=greaterEqualHead->next;
        greaterEqual->next=NULL;

        ListNode* newHead=smallerHead->next;
        delete smallerHead;
        delete greaterEqualHead;

        return newHead;
    }
};