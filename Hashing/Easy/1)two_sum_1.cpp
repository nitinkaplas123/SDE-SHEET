Code-:
vector<int> twoSum(vector<int>& nums, int target) {
        vector<int>ans;
        int n=nums.size();
        unordered_map<int,int>m;
        m[nums[0]]=0;

        for(int i=1;i<n;i++)
        {
            if(m.find(target-nums[i])!=m.end())
            return {m[target-nums[i]],i};
            else
            m[nums[i]]=i;
        }
        return {-1,-1};
}