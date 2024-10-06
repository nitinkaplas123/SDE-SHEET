Solution 1-:
Steps-:
1)Swap nodes using values.

Code-: Time->O(N) 
int count(ListNode* head)
{
        int c=0;
        while(head!=NULL)
        {
            c++;
            head=head->next;
        }
        return c;
}

ListNode* swapNodes(ListNode* head, int k)
{
        int n=count(head);
        ListNode* start=head;
        ListNode* end=head;
        for(int i=0;i<k-1;i++)
        {
            start=start->next;
        }

        for(int i=0;i<n-k;i++)
        {
            end=end->next;
        }

        swap(start->val,end->val);
        return head;
}


Solution 2-:
Same idea but replace count function using slow and fast pointer 

Code-: Time->O(N)
ListNode* swapNodes(ListNode* head, int k) {
        ListNode* slow=head;
        ListNode* fast=head;
        for(int i=0;i<k-1;i++)
        {
            slow=slow->next;
        }
        ListNode* temp=slow;

        while(slow->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next;
        }
        swap(temp->val,fast->val);
        return head;
    }



Solution 3-:
Now if the values are so big then we cannot swap using values we have to swap using pointers  only

Steps-:
There are multiples cases-:
   (2*k-1==n)
1) when no. of nodes is odd and we  swap center node of it which is same from start and end of linked list.
2) if k==1 then return y
3) if k==n then return x
4) else return head by default.

Here u can see more on Notebook 10 at last pages

Code-:
int count(ListNode* head)
{
        int c=0;
        while(head!=NULL)
        {
            c++;
            head=head->next;
        }
        return c;
}
    
ListNode* swapNodes(ListNode* head, int k) 
{
       int n=count(head);
       ListNode* x_prev=NULL;
       ListNode* y_prev=NULL;
       ListNode* x=head;
       ListNode* y=head;
       
       // when no. of nodes is odd and we  swap center node of it which is same 
       // from start and end of linked list.
       if(2*k-1==n) return head;
       
       int count=k-1;
       while(count--)
       {
           x_prev=x;
           x=x->next;
       }

       count=n-k;
       while(count--)
       {
           y_prev=y;
           y=y->next;
       }

       if(x_prev)
       x_prev->next=y;

       if(y_prev)
       y_prev->next=x;

       ListNode* temp=x->next;
       x->next=y->next;
       y->next=temp;


       if(k==1)
       return y;
       if(k==n)
       return x;

       return head;
}