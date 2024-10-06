https://www.geeksforgeeks.org/problems/add-1-to-a-number-represented-as-linked-list/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=add-1-to-a-number-represented-as-linked-list

Solution 1-:
Steps-:
1) Make carry=1
2) and use only head1 as curr1 to traverse the linked list.
3) As we have to do it in constant space so we are updating head->data=sum.

Code-:
Node* reverse(Node* head)
    {
        Node* prev=NULL;
        Node* curr=head;
        while(curr!=NULL)
        {
            Node* save=curr->next;
            curr->next=prev;
            prev=curr;
            curr=save;
        }
        return prev;
    }
    Node* addOne(Node *head) 
    {
        
        head= reverse(head);
        Node* new_head=head;
        
        int carry=1;
        int sum;
        Node* temp;
        while(head!=NULL)
        {
            sum=carry+head->data;
            head->data=(sum%10);
            temp=head;
            carry=sum/10;
            head=head->next;
        }
        
        if(carry!=0)
        temp->next=new Node(carry);
        return reverse(new_head);
    }