Steps-:
1)using hashset 

Time->O(2*N) ->O(N)
Space->O(N)

Code-:
int longestConsecutive(vector<int>&arr) {
        int n=arr.size();
        unordered_set<int>s;
        for(int i=0;i<n;i++)
        {
            s.insert(arr[i]);
        }
        
        int ans=0;
        for(int i=0;i<n;i++)
        {
            if(s.find(arr[i]-1)==s.end())
            {
                int count=0;
                int val=arr[i];
                while(s.find(val)!=s.end())
                {
                    count++;
                    val++;
                }
                ans=max(ans,count);
            }
        }
        return ans;
}

Solution 2-:
Steps-:
1)Using sorting.
2)if diff=1 its consecttive.
  if diff=0 its continue. means donot break the consecutive just ignore that guy.

Time->O(Nlog(N))
Space->O(1)
Code-:
int longestConsecutive(vector<int>& nums) {
         int n=nums.size();
         if(n==0) return 0;
         sort(nums.begin(),nums.end());

         int ans=0;
         int count=1;
         for(int i=1;i<n;i++)
         {
             if(nums[i]-nums[i-1]==1)
             count++;
             else if(nums[i]-nums[i-1]==0)
             continue;
             else
             {
                ans=max(ans,count);
                count=1;
             }
         }
         ans=max(ans,count);
         return ans;
}