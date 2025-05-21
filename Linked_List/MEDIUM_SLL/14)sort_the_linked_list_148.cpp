Solution 1-:
Steps-:
1)Make a pair of vector where we store {curr->val,curr} value and node itself.
2)now we need to sort the linked list so we sort the vector acc. to 1st value.
3)now we traverse the vector and v[i].second->next=v[i+1].second
4)At last we return the head so here head is (v[0].second)


Code-: Time->O(n) Space ->O(N)
ListNode* sortList(ListNode* head) {
        ListNode* curr=head;
        if(head==NULL || head->next==NULL) return head;
        vector<pair<int,ListNode*>>v;
        while(curr!=NULL)
        {
            v.push_back({curr->val,curr});
            curr=curr->next;
        }
        
        sort(v.begin(),v.end());
        int n=v.size();
        for(int i=0;i<n-1;i++)
        {
            v[i].second->next=v[i+1].second;
        }
        v[n-1].second->next=NULL;
        return v[0].second;
}



Solution 2-: Using merge Sort.


Time Complexity: O(Nlog(N))
Space Complexity: O(log(N))


Code:
ListNode* middle(ListNode* head)
{
    ListNode* prev=NULL;
    ListNode* slow=head;
    ListNode* fast=head;

    while(fast!=NULL and fast->next!=NULL)
    {
        prev=slow;
        slow=slow->next;
        fast=fast->next->next;
    }
    return prev;
}

ListNode* mergeTwoLinkedList(ListNode* head1,ListNode* head2)
{
    if(head1==NULL) return head2;
    if(head2==NULL) return head1;

    if(head1->val<head2->val)
    {
        head1->next=mergeTwoLinkedList(head1->next,head2);
        return head1;
    }
    else
    {
        head2->next=mergeTwoLinkedList(head1,head2->next);
        return head2;
    }
}

ListNode* sortList(ListNode* head) {
    if(head==NULL || head->next==NULL) return head;

    ListNode* mid=middle(head);

    ListNode* left=head;
    ListNode* right=mid->next;
    
    mid->next=NULL;

    left=sortList(left);
    right=sortList(right);

    return mergeTwoLinkedList(left,right);
}




