Solution 1-:
Steps-:
Case1 -:
1)when n==1 return 0;

Case2 -:
when n==2 return abs(nums[1]-nums[0]);

Case3-:
int val1= nums[n-1]-nums[n-2] + helper(n-1);
int val2= nums[n-1]-nums[n-3] + helper(n-2);
return min(val1,val2);


Code-:
int helper(vector<int>&height,int n)
{
        if(n==1) return 0;
        if(n==2)
        return abs(height[n-1]-height[n-2]);
        else
        {
            int val1=abs(height[n-1]-height[n-2])+helper(height,n-1);
            int val2=abs(height[n-1]-height[n-3])+helper(height,n-2);
            return min(val1,val2);
        }
}
int minCost(vector<int>& height) {
       int n=height.size();
       return helper(height,n);
}



Solution 2-:
Steps-:
1)using memo 

Code-:
int helper(vector<int>&memo,vector<int>&height,int n)
{
        if(n==1) return 0;
        if(n==2)
        return abs(height[n-1]-height[n-2]);
        if(memo[n]!=-1) return memo[n];
        else
        {
            int val1=abs(height[n-1]-height[n-2])+helper(memo,height,n-1);
            int val2=abs(height[n-1]-height[n-3])+helper(memo,height,n-2);
            return memo[n]=min(val1,val2);
        }
}
int minCost(vector<int>& height) {
       int n=height.size();
       vector<int>memo(n+1,-1);
       return helper(memo,height,n);
}



Solution 3-:
Steps-:
1)using tabulation 


Code-:
int minCost(vector<int>& height) {
       int n=height.size();
       vector<int>dp(n+1,0);
   
       dp[1]=0;
       dp[2]=abs(height[1]-height[0]);
       for(int i=3;i<=n;i++)
       {
           int val1=abs(height[i-1]-height[i-2]) + dp[i-1];
           int val2=abs(height[i-1]-height[i-3]) + dp[i-2];
           dp[i]=min(val1,val2);
       }
       return dp[n];
}




Solution 4-:
Steps-:
1)Space optimization 


Code-:
int minCost(vector<int>& height) 
{
       int n=height.size();
       if(n==1) return 0;
       int a=0;
       int b=abs(height[1]-height[0]);
       if(n==2) return b;
       int c;
       for(int i=3;i<=n;i++)
       {
           int val1=abs(height[i-1]-height[i-2]) + b;
           int val2=abs(height[i-1]-height[i-3]) + a;
           c=min(val1,val2);
           a=b;
           b=c;
       }
       return c;
}