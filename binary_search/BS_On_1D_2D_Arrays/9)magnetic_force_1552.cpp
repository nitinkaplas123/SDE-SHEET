Same as aggresive cows

Here we use-:
low=1;
high=1e9;

Solution 1-:
int maxDistance(vector<int>& position, int m) {
        sort(position.begin(),position.end());
        int n=position.size();
        int low=1;
        int high=1e9;
        
        int ans;

        while(low<=high)
        {
            int mid=(low+high)/2;
            int curr=1;
            int prev=0;
            int count=1;
            while(curr<n and count<m)
            {
                if(position[curr]-position[prev]>=mid)
                {
                    count++;
                    prev=curr;
                    curr++;
                }
                else
                curr++;
            }
            if(count<m)
            high=mid-1;
            else
            {
                ans=mid;
                low=mid+1;
            }
        }
        return ans;
    }