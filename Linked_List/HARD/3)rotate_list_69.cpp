Solution 1-:
Steps-:
1)Corner cases-:
  1. if head is null or head->next==NULL here k is any value we should return head
  2. if k >n then k=k%n to make in the range 
  3. if k==0 then no rotation will happen so return head

2)Now normal visaulise the problem 
3)like go to our new_head and store it 
4)then linked the last node to the head
5)then prev node of new_head make (prev->next=NULL)
6)return the new_head

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
    ListNode* rotateRight(ListNode* head, int k) {
      if(head==NULL ||head->next==NULL) return head;
        int n=count(head);
        k=k%n;
        if(k==0) return head;
        k=n-k;
       

        ListNode* prev=NULL;
        ListNode* curr=head;
        while(k--)
        {
            prev=curr;
            curr=curr->next;
        }

        ListNode* new_head=curr;
        while(curr->next!=NULL)
        {
            curr=curr->next;
        }
        curr->next=head;
        prev->next=NULL;
        return new_head;
    }