Time -> O(Nlog(N)) 
Space-> O(N)

Code-:
int lastStoneWeight(vector<int>&nums) {
        int n=nums.size();

        priority_queue<int>pq;
        for(int i=0;i<n;i++)
        {
            pq.push(nums[i]);
        }

        while(pq.size()>1)
        {
            int first_max=pq.top();
            pq.pop();
            int second_max=pq.top();
            pq.pop();

            if(first_max!=second_max)
            pq.push(first_max-second_max);
        }
        return (pq.empty())?0:pq.top();
}