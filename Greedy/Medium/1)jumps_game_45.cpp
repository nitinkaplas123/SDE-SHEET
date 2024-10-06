Code-:
int jump(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return 0;
        int jumps=1;
        int steps=nums[0];
        int max_reach=nums[0];

        for(int i=1;i<n-1;i++)
        {
            max_reach=max(max_reach,i+nums[i]);
            steps--;

            if(steps==0)
            {
                jumps++;
                steps=max_reach-i;
            }
        }
        return jumps;
}