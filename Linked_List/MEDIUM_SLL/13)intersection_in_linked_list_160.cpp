Solution 1-:
Steps-:
1)Make a hashset where we add all the nodes  of list1 in it.
2)Now we traverse a list2 and if list2 node is present in hashset that means that is the intersection point.


Code-: Time->O(n) Space ->O(n)
 ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_set<ListNode*>s;
        ListNode* curr=headA;
        while(curr!=NULL)
        {
            s.insert(curr);
            curr=curr->next;
        }

        curr=headB;
        while(curr!=NULL)
        {
            if(s.find(curr)!=s.end())
            return curr;
            curr=curr->next;
        }
        return NULL;
    }






Solution 2-:
Steps-:
1)Find the count diff of nodes between both linked list
2)Now list which have more nodes have to move diff steps from head.
3)Now both are at equal distance from intersection.
4)Now curr1 and curr2 move with 1 step and when we find curr1==curr2 that is the intersection point of linked list.


Code-: Time->O(N) Space ->O(1)
 int helper(ListNode* head)
    {
        int count=0;
        while(head!=NULL)
        {
            count++;
            head=head->next;
        }
        return count;
    }
    ListNode* solve(ListNode* curr1,ListNode* curr2)
    {
         while(curr1!=curr2)
         {
             curr1=curr1->next;
             curr2=curr2->next;
         }
         return curr1;
    }
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int count1=helper(headA);
        int count2=helper(headB);
        if(count2>count1)
        {
           int diff=count2-count1;
           ListNode* curr=headB;
           while(diff--)
           {
               curr=curr->next;
           }
           return solve(headA,curr);
        }
        else
        {
            int diff=count1-count2;
            ListNode* curr=headA;
            while(diff--)
            {
                curr=curr->next;
            }
            return solve(curr,headB);
        }
    }


Solution 3-:
Steps-:
1)Here we are at curr1=headA curr2=headB
2)Now we move 1 step both 
3)If any of the node reach to null 
  for eg. curr1=NULL  then curr1=headB
  if      curr2==NULL then curr2=headA
  this make the diff finished bw both the linked list
4)Now both are at same distance from intersection if there is-:
  Move both with 1 step
  Two cases-:
  1. If there is intersection then return the node of it.
  2. If there is no intersection then both curr1 and curr2 reach to NULL and return NULL when while loop terminate.


Code-:
 ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* curr1=headA;
        ListNode* curr2=headB;

        while(curr1!=curr2)
        {
           curr1=curr1->next;
           curr2=curr2->next;
           
           if(curr1==NULL and curr2==NULL)
           return NULL;
           if(curr1==NULL)
           curr1=headB;
           if(curr2==NULL)
           curr2=headA;
        }
        return curr1;
}
