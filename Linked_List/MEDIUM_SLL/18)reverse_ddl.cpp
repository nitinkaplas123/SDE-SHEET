https://www.geeksforgeeks.org/problems/reverse-a-doubly-linked-list/1

Solution 1-:
Steps-:
1)Using recursion 
2)Same idea as we do in reverse a singly linked list.

Code-:
DLLNode* reverseDLL(DLLNode* head) {
           if(head==NULL || head->next==NULL)
           return head;
           
           DLLNode* new_head=reverseDLL(head->next);
           DLLNode* head_next=head->next;
           
           head_next->next=head;
           head->prev=head_next;
           head->next=NULL;
           return new_head;
}


Solution 2-:
Steps-:
1)Iterative method.

Code-:
Node* reverseDLL(Node * head)
{
        Node* prev=NULL;
        Node* curr=head;
        
        while(curr!=NULL)
        {
            Node* save=curr->next;
            curr->next=prev;
            curr->prev=save;
            prev=curr;
            curr=save;
        }
        return prev;
}
