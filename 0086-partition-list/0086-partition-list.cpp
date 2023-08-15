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
        if(!head || !head->next)return head;
        ListNode* sHead=new ListNode(0);
        ListNode* sH=sHead;
        ListNode* gHead=new ListNode(0);
        ListNode* gH=gHead;

        ListNode* curr=head;

        while(curr){
            if(curr->val<x){
                sH->next=curr;
                sH=sH->next;
            }
            else{
                gH->next=curr;
                gH=gH->next;
            }
            curr=curr->next;
        }
        sH->next=gHead->next;
        gH->next=NULL;
        
        return sHead->next;

        
    }
};