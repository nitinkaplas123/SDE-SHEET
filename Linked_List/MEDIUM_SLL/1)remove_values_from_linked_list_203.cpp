Solution 1-:

Time->O(N)
ListNode* removeElements(ListNode* head, int val) {
        ListNode* dummy=new ListNode(-1);
        ListNode* temp=dummy;
        
        ListNode* curr=head;
        while(curr!=NULL)
        {
            if(curr->val!=val)
            {
                temp->next=curr;
                temp=curr;
            }
            curr=curr->next;
        }
        temp->next=NULL;
        return dummy->next;
}