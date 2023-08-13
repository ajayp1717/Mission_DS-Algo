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
        for(int i=0;i<left-1;++i){
            bef=bef->next;            //reach to left
        }
        ListNode* curr=bef->next; 
        //maintaining pointers for future use
        ListNode* newTail=curr;         

        ListNode* prev=NULL;     
        ListNode* nxt=NULL;
        for(int i=left;i<=right;++i){
            nxt= curr->next;
            curr->next=prev;           //reverse left to right
            prev=curr;
            curr=nxt;
        }
        bef->next=prev;
        newTail->next=curr;   //connect reversed sublist
        
        return dummy->next;
    }
};