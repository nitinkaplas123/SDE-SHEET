Solution 1-:
Steps-:
1)Generate all subset. 
2)When we generate a subset then we take abs diff then update ans accordingly.


Time->O(2*n)
Space ->O(N)
Code-:
void helper(vector<int>& nums,int index,int n,int sum,int goal,int &ans)
{
        if(index==n)
        {
            int diff=abs(sum-goal);
            ans=min(ans,diff);
            return ;
        }
        helper(nums,index+1,n,sum,goal,ans);
        sum+=nums[index];
        helper(nums,index+1,n,sum,goal,ans);
}
int minAbsDifference(vector<int>& nums, int goal) {
        int n=nums.size();
        int ans=INT_MAX;
        int sum=0;
        helper(nums,0,n,sum,goal,ans);
        return ans;
}