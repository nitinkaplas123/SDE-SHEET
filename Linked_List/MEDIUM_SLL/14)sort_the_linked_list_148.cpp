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

Pending.