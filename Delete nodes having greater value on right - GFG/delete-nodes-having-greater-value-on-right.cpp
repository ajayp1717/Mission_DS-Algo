//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;

struct Node
{
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};


void print(Node *root)
{
    Node *temp = root;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}



// } Driver Code Ends
/*

The structure of linked list is the following

struct Node
{
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};
*/
class Solution
{
    public:
    Node* reverseLL(Node* node){
        Node* prev=NULL;
        Node* curr=node;
        Node* nxt=NULL;
        
        while(curr){
            nxt=curr->next;;
            curr->next=prev;
            prev=curr;
            curr=nxt;
        }
        node=prev;
    }
    Node *compute(Node *head)
    {
        // your code goes here
        if(!head || !head->next)return head;
        
        head=reverseLL(head);
        Node* curr=head;
        int maxi=curr->data;
        while(curr->next){
            if(curr->next->data < maxi){
                curr->next=curr->next->next;
            }
            else curr=curr->next;
            maxi=max(maxi,curr->data);
            
        }
        
        return reverseLL(head);
    }
    
    
    
};
   


//{ Driver Code Starts.

int main()
{
    int T;
	cin>>T;

	while(T--)
	{
		int K;
		cin>>K;
		struct Node *head = NULL;
        struct Node *temp = head;

		for(int i=0;i<K;i++){
		    int data;
		    cin>>data;
			if(head==NULL)
			    head=temp=new Node(data);
			else
			{
				temp->next = new Node(data);
				temp = temp->next;
			}
		}
        Solution ob;
        Node *result = ob.compute(head);
        print(result);
        cout<<endl;
    }
}

// } Driver Code Ends