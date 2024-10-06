Solution 1-:
Approach ( Using List )
To Check if the Given Linked List is palindrome or not , we can copy the data in list and then check if the list if palindrome or not.

Complexity
Time complexity: O(N)
Space complexity: O(N)


Solution 2-:
1)First push all data in stack, and then traverse linked list and keep popping element from stack one by one, 
so stack will give you element from last.

Code-:
bool isPalindrome(ListNode* head) 
{
        stack<int> stack;
        ListNode* curr = head;
        while (curr) {
            stack.push(curr->val);
            curr = curr->next;
        }
        curr = head;
        while (curr && curr->val == stack.top()) {
            stack.pop();
            curr = curr->next;
        }
        return curr == nullptr;
}


Solution 3-:
Steps-:
1)Find the middle node of the linked list.
Case 1-:
If the number of nodes is odd 

   prev slow
1-> 2-> 2-> 1-> 1 

here we go one step ahead.

       prev slow
1-> 2-> 2-> 1-> 1 

Case2-:
If the number of nodes is even.

   prev slow
1-> 2-> 2-> 1

2)Now reverse the nodes from slow to end of the linked list.
mid=reverse(slow);
prev->next=mid.

3)Now slow=head 
      fast=mid.
4)Run both by 1 step and if any point if (slow!=fast) return false.
5)else at the end we have to return true.



Code-:
ListNode* reverse(ListNode* head)
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

bool isPalindrome(ListNode* head) 
{
        if(head->next==NULL) return true;

        // find middle element 
        ListNode* slow=head;
        ListNode* fast=head;
        ListNode* prev=NULL;

        while(fast!=NULL and fast->next!=NULL)
        {
            prev=slow;
            slow=slow->next;
            fast=fast->next->next;
        }
        
        // odd number of elements 
        if(fast!=NULL)
        {
            prev=slow;
            slow=slow->next;
        }
        
        ListNode* mid=reverse(slow);
        prev->next=mid;

        slow=head;
        fast=prev->next;
        while(fast!=NULL)
        {
            if(slow->val!=fast->val) return false;
            else
            {
                slow=slow->next;
                fast=fast->next;
            }
        }
        return true;
}