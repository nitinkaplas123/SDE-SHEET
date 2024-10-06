Solution 1-:
using iterative method
Steps-:
1)Just prev=NULL and curr=head
2)Now at every step curr->next=prev and prev=curr curr=curr->next

Code-: Time->O(N)
ListNode* reverseList(ListNode* head) 
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


Solution 2-:
Using Recursive method

Steps-:
1)Doing same as we do in sol 1

Code-:
ListNode* helper(ListNode* prev,ListNode* curr)
{
        if(curr==NULL) return prev;
        
        ListNode* save=curr->next;
        curr->next=prev;
        return helper(curr,save);
}
ListNode* reverseList(ListNode* head)
{
        ListNode* curr=head;
        ListNode* prev=NULL;
        return helper(prev,curr);
}


Solution 3-: using recursion

Steps-:
