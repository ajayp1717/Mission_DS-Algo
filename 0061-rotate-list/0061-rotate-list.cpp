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
    int LLsize(ListNode* head){
        ListNode* curr=head;
        int l=0;
        while(curr){
            l++;
            curr=curr->next;
        }
        return l;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL)return NULL;
        if(head->next==NULL)return head;
        int n=LLsize(head);
        ListNode* oTail = head;
        for (int i = 0; oTail->next != nullptr; i++) {
            oTail = oTail->next;
        }
        oTail->next = head;
        ListNode* nTail=head;
        int i=0;
        while((i++)<n-k%n-1){
            nTail=nTail->next;
        }
        ListNode* nHead=nTail->next;
        nTail->next=NULL;
        return nHead;
    }
};