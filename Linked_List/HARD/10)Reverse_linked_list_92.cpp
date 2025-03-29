https://www.youtube.com/watch?v=bRZ_Fy4zRRY

Solution 1:

Code:
ListNode* Reverse(ListNode* head)
{
        ListNode* curr=head;
        ListNode* prev=NULL;

        while(curr!=NULL)
        {
            ListNode* save=curr->next;
            curr->next=prev;
            prev=curr;
            curr=save;
        }
        return prev;
}
ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* dummy=new ListNode(0);
        dummy->next=head;
        ListNode* l_prev=NULL;
        ListNode* l=head;
        ListNode* r=head;
        ListNode* r_next=NULL;
 
        for(int i=0;i<left-1;i++)
        {
            l_prev=l;
            l=l->next;
        }

        for(int i=0;i<right-1;i++)
        {
            r=r->next;
        }
        r_next=r->next;

        r->next=NULL;
        ListNode* rev=Reverse(l);

        // if(r_next)
        l->next=r_next;
        if(l_prev)
        l_prev->next=rev;
        else
        dummy->next=rev;
        return dummy->next;
}



Solution 2:

Code:
ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(head==NULL || head->next==NULL)
        return head;

        ListNode* dummy=new ListNode(0);
        dummy->next=head;

        ListNode* prev=dummy;
        for(int i=1;i<=left-1;i++)
        {
            prev=prev->next;
        }
        ListNode* curr=prev->next;

        for(int i=1;i<=right-left;i++)
        {
            ListNode* temp=prev->next;
            prev->next=curr->next;
            curr->next=curr->next->next;
            prev->next->next=temp;
        }
        return dummy->next;
}