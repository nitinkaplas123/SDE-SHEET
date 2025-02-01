https://www.geeksforgeeks.org/problems/minimum-sum-partition3317/1


Code-:
int minDifference(vector<int>& arr) 
{
        int n=arr.size();
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=arr[i];
        }
        
        int dp[n+1][sum+1];
        for(int i=0;i<=n;i++){
            for(int j=0;j<=sum;j++){
                if(i==0){
                    if(j==0) dp[i][j]=1;
                    else dp[i][j]=0;
                }
                else if(j>=arr[i-1]){
                    dp[i][j]=dp[i-1][j-arr[i-1]] || dp[i-1][j];
                }
                else
                dp[i][j]=dp[i-1][j];
            }
        }
        
        int ans=INT_MAX;
        for(int i=0;i<=sum/2;i++){
            int s1=i;
            int s2=sum-s1;
            if(dp[n][s1])
            ans=min(ans,s2-s1);
        }
        return ans;
}