https://www.geeksforgeeks.org/problems/minimum-sum-partition3317/1

Solution 1-:

eg.
arr[]={1,2,7}

Steps-:
1)sum of all elements 
2)Make a dp array where we store dp[n+1][sum+1] where we find if 
  i=0 to i=sum we make a subset from given array which is equal to i for all cases.
3)Now when we filled with array we have to find the min diff bw s1 and s2.
  if sum =10 
  s1=may be 5 or less.
  s2=may be 5 or more.
  so min ans=5-5
4)So we run a loop from i=0;i<=sum/2 
  s1=i
  s2=sum-i
  now check if dp[n][s1] is a subset or not if it is then no need to check for dp[n][s2].
5) ans=min(ans,s2-s1)
6) return ans;


int minDifference(int arr[], int n)  
{ 
	int sum=0;
	for(int i=0;i<n;i++)
	{
	        sum+=arr[i];
	}
	    
	int dp[n+1][sum+1];
	for(int i=0;i<=n;i++)
	{
	    for(int j=0;j<=sum;j++)
	    {
	            if(i==0)
	            {
	                if(j==0) dp[i][j]=1;
	                else     dp[i][j]=0;
	            }
	            else if(j>=arr[i-1])
	            dp[i][j]= dp[i-1][j-arr[i-1]] || dp[i-1][j];
	            else
	            dp[i][j]=dp[i-1][j];
	    }
    }
	    
    int ans=INT_MAX;
    for(int i=0;i<=sum/2;i++)
    {
 	 int s1=i;
	 int s2=sum-s1;
	 if(dp[n][s1]==1)
	 ans=min(ans,s2-s1);
    }
    return ans;
} 