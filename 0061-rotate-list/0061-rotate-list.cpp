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
        ListNode* curr=head;
        int l=0;
        while(++l && curr){
            if(l==n){
                curr->next=head;
                break;
            }
            curr=curr->next;
        }
        l=0;
        curr=head;
        while(++l<n-k%n ){
            curr=curr->next;
        }
        head=curr->next;
        curr->next=NULL;

        return head;
    }
};