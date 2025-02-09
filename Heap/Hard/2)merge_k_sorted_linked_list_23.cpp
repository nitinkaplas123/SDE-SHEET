Code-: Time->O(klog(k)) + O(n-k)log(k)  -> O(nlog(k)) 
class comp
{
    public:
    bool operator()(ListNode* l1,ListNode* l2)
    {
        return l1->val>l2->val;
    }
};


class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n=lists.size();
        priority_queue<ListNode*,vector<ListNode*>,comp>pq;
        
        for(int i=0;i<n;i++)
        {
            if(lists[i]!=NULL)
            pq.push(lists[i]);
        }
        
        ListNode* curr=NULL;
        ListNode* head=NULL;
        while(pq.empty()==false)
        {
            ListNode* temp=pq.top();
            pq.pop();

            if(temp->next)
            pq.push(temp->next);

            if(head==NULL)
            {
                head=temp;
                curr=temp;
            }
            else
            {
                curr->next=temp;
                curr=temp;
            }
        }
        return head;
}