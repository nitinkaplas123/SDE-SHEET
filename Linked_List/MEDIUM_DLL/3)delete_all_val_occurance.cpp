https://www.geeksforgeeks.org/problems/delete-all-occurrences-of-a-given-key-in-a-doubly-linked-list/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=delete-all-occurrences-of-a-given-key-in-a-doubly-linked-list


Steps-:
1)here we have to just update the things in head_ref.
  here we are not returning anything.
2)So our logic is correct.
  Just we are making our new_head which we have to equal to head_ref.
  new_head=*head_ref.


Code-: Time->O(N)
void deleteAllOccurOfX(struct Node** head_ref, int x) {
        Node* new_head=NULL;
        Node* temp=NULL;
        
        Node* curr=*head_ref;
        while(curr!=NULL)
        {
            if(curr->data!=x)
            {
                if(new_head==NULL)
                {
                    new_head=curr;
                    temp=curr;
                }
                else
                {
                     temp->next=curr;
                     curr->prev=temp;
                     temp=curr;
                }
            }
            curr=curr->next;
        }
        temp->next=NULL;
        **head_ref=*new_head;
        return ;
}