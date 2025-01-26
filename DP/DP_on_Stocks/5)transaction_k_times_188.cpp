Solution 1-:
Steps-:
1)same as atmost 2 transactions.
2)there we add a cap=2 here cap=k.


Code-:
int helper(vector<int>& prices,int index,int buy,int k,int n)
{
        if(k==0 || index==n) return 0;

        if(buy)
        {
            int take=-prices[index]+helper(prices,index+1,0,k,n);
            int not_take=0+helper(prices,index+1,1,k,n);
            return max(take,not_take);
        }
        else
        {
            int sell=prices[index]+helper(prices,index+1,1,k-1,n);
            int not_sell=0+helper(prices,index+1,0,k,n);
            return max(sell,not_sell);
        }
}
int maxProfit(int k, vector<int>& prices) {
        int n=prices.size();
        int index=0;
        int buy=1;
        return helper(prices,index,buy,k,n);
}



Solution 2-:
Steps-:
1)using memo.

Time->O(2*k*n)
Code-:
int helper(int memo[2][101][1000],vector<int>& prices,int index,int buy,int k,int n)
{
        if(k==0 || index==n) return 0;
        if(memo[buy][k][index]!=-1) return memo[buy][k][index];

        if(buy)
        {
            int take=-prices[index]+helper(memo,prices,index+1,0,k,n);
            int not_take=0+helper(memo,prices,index+1,1,k,n);
            return memo[buy][k][index]=max(take,not_take);
        }
        else
        {
            int sell=prices[index]+helper(memo,prices,index+1,1,k-1,n);
            int not_sell=0+helper(memo,prices,index+1,0,k,n);
            return memo[buy][k][index]=max(sell,not_sell);
        }
}
int maxProfit(int k, vector<int>& prices) {
        int n=prices.size();
        int index=0;
        int buy=1;
        int memo[2][101][1000];
        memset(memo,-1,sizeof(memo));
        return helper(memo,prices,index,buy,k,n);
}



Solution 3-:
Steps-:
1)using tabulation.

Time->O(2*k*n)
Space->O(2*k*n)
Code-:
int maxProfit(int k, vector<int>& prices) {
        int n=prices.size();
        int dp[2][k+1][n+1];
        for(int index=0;index<=n;index++)
        {
            for(int buy=0;buy<=1;buy++)
            {
                dp[buy][0][index]=0;
            }
        }

        for(int buy=0;buy<=1;buy++)
        {
            for(int cap=0;cap<=k;cap++)
            {
                dp[buy][cap][n]=0;
            }
        }

        for(int index=n-1;index>=0;index--)
        {
            for(int cap=1;cap<=k;cap++)
            {
                for(int buy=0;buy<=1;buy++)
                {
                    if(buy)
                    {
                     int take=-prices[index]+dp[0][cap][index+1];
                     int not_take=0+dp[1][cap][index+1];
                     dp[buy][cap][index]=max(take,not_take);
                    }
                    else
                    {
                     int sell=prices[index]+dp[1][cap-1][index+1];
                     int not_sell=0+dp[0][cap][index+1];
                     dp[buy][cap][index]=max(sell,not_sell);
                    }
                }
            }
        }
        return dp[1][k][0];
}




Solution 4-:
Steps-:
1)space optimisation.


Time->O(2*k*n)
Space->O(2*k)

Code-:
int maxProfit(int k, vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>>prev(2,vector<int>(k+1,0));
        vector<vector<int>>curr(2,vector<int>(k+1,0));
        for(int index=n-1;index>=0;index--)
        {
            for(int cap=1;cap<=k;cap++)
            {
                for(int buy=0;buy<=1;buy++)
                {
                    if(buy)
                    {
                     int take=-prices[index]+prev[0][cap];
                     int not_take=0+prev[1][cap];
                     curr[buy][cap]=max(take,not_take);
                    }
                    else
                    {
                     int sell=prices[index]+prev[1][cap-1];
                     int not_sell=0+prev[0][cap];
                     curr[buy][cap]=max(sell,not_sell);
                    }
                }
            }
            prev=curr;
        }
        return curr[1][k];
}