Solution 1-:
Steps-:
1)Here we just swap the values of curr with curr->next

Code-: Time->O(n) 
ListNode* swapPairs(ListNode* head) 
{
        ListNode* curr=head;
        while(curr!=NULL and curr->next!=NULL)
        {
            swap(curr->val,curr->next->val);
            curr=curr->next->next;
        }
        return head;
}


Solution 2-:
Steps-:
Using recursion
1)Corner Case-:if head is null or there is only one node which means we cannot do swapping so return head;
2)Make temp variable node to next of head node 
3)And make head->next=f(next head after one node)
4)Odd position is head and even position is temp
eg. [1,2,3,4]

func1 
1)here 1 is head, 2 is temp
func2 
2)here 3 is head, 4 is temp

when we reach at end 
2)temp->next=head   means 4->3
return temp to previous func  return 4 

1)in 1st func 1 is head  means 1->4->3
  temp->next=head 
  here 2 is temp         means 2->1->4->3

  return temp            return 2 node 


Code-: Time->O(n)
ListNode* swapPairs(ListNode* head) 
{
        if(head==NULL || head->next==NULL) return head;
        ListNode* temp=head->next;
        head->next=swapPairs(head->next->next);
        temp->next=head;
        
        return temp;
}



