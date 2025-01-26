Solution 1-:
Steps-:
1)using max heap 


Time->O(nlog(n))
Space->O(n)

Code-:
int findKthLargest(vector<int>& nums, int k) {
        int n=nums.size();
        priority_queue<int>pq;
        for(int i=0;i<n;i++)
        {
            pq.push(nums[i]);
        }
        
        k--;
        while(k--)
        {
            pq.pop();
        }
        return pq.top();
}


Solution 2-:
Steps-:
1)using min heap and making the heap size of k. 



Time->O(Nlog(k))
Space->O(K)
Code-:
int findKthLargest(vector<int>& nums, int k) {
        int n=nums.size();
        priority_queue<int,vector<int>,greater<int>>pq;
        for(int i=0;i<k;i++)
        {
            pq.push(nums[i]);
        }

        for(int i=k;i<n;i++)
        {
            int top=pq.top();
            if(top<nums[i])
            {
                pq.pop();
                pq.push(nums[i]);
            }
        }
        return pq.top();
}