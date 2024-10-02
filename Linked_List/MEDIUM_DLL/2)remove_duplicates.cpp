https://www.geeksforgeeks.org/problems/remove-duplicates-from-a-sorted-doubly-linked-list/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=remove-duplicates-from-a-sorted-doubly-linked-list

Steps-:
1)prev will be pointing to the first node.
2)curr will be pointing to the last node.

Code-:
Node * removeDuplicates(struct Node *head)
{
        if(head->next==NULL) return head;
        Node* prev=head;
        Node* curr=head->next;
        
        while(curr!=NULL)
        {
            if(prev->data!=curr->data)
            {
                prev->next=curr;
                curr->prev=prev;
                prev=curr;
            }
            curr=curr->next;
        }
        prev->next=NULL;
        return head;
}