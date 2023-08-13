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
    // ListNode* reverseLL(ListNode* s,ListNode* e){

    //     if(!head || !head->next)return head;

    // }
    ListNode* reverseBetween(ListNode* head, int left, int right) {

        if(!head || !head->next || left==right)return head;
        
        ListNode* dummy=new ListNode(0);
        dummy->next=head;
        
        ListNode* bef=dummy; //before
        ListNode* prev=NULL;     
        ListNode* nxt=NULL;

        for(int i=0;i<left-1;++i){
            bef=bef->next;
        }
        ListNode* curr=bef->next; 
        ListNode* newTail=curr;

        for(int i=left;i<=right;++i){
            nxt= curr->next;
            curr->next=prev;
            prev=curr;
            curr=nxt;
        }
        bef->next=prev;
        newTail->next=curr;
        
        return dummy->next;
        
    }
};