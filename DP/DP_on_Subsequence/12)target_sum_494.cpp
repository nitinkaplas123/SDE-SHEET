Steps-:
1)(s1+s2)=sum.
  (s1-s2)==target

  2s1=(sum+target)
  s1=(sum+target)/2;

Case 1-:
if(n==1) 
{
    if(nums[0]==abs(target)) return 1;
    else return 0;
}

Case 2-:
means (if (sum+target is odd)) -> we cannot divide into 2 arrays 
if(s1%2!=0) means its odd we cannot make it. return 0;

Case 3-:
count the perfect sum of (s1) in helper function.

int helper(vector<int>&nums,int sum,int n)
{
        if(n==0)
        {
            if(sum==0) return 1;
            else
            return 0;
        }
        if(sum>=nums[n-1])
        return helper(nums,sum-nums[n-1],n-1) + helper(nums,sum,n-1);
        else
        return helper(nums,sum,n-1);
}

int perfectSum(vector<int>&nums,int sum)
{
        int n=nums.size();
        return helper(nums,sum,n);
}

int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        if(n==1) 
        {
            if(nums[0]==abs(target)) return 1;
            else return 0;
        }
        int sum=0;
        for(int i=0;i<n;i++)
        {
            sum+=nums[i];
        }
        if((sum+target)%2!=0) return 0;
        int val=(sum+target)/2; 
        return perfectSum(nums,val);
}