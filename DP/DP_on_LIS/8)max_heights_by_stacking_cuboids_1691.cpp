Reference -> https://www.youtube.com/watch?v=rhEZhtoe_EQ

Code-:
 int maxHeight(vector<vector<int>>& cuboids) {
        int n=cuboids.size();
        int ans=0;
        vector<int>lis(n,0);

        for(auto &x:cuboids)
        {
            sort(x.begin(),x.end());
        }

        sort(cuboids.begin(),cuboids.end());

        for(int i=0;i<n;i++)
        {
            lis[i]=cuboids[i][2];
            for(int j=i-1;j>=0;j--)
            {
                if( cuboids[i][0]>=cuboids[j][0] and cuboids[i][1]>=cuboids[j][1] and 
                cuboids[i][2]>= cuboids[j][2])
                lis[i]=max(lis[i],cuboids[i][2]+lis[j]);
            }
            ans=max(ans,lis[i]);
        }
        return ans;
    }