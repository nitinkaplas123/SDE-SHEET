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