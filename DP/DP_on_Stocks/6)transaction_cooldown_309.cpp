Solution 1-:
Steps-:
1)using recursion. 
2)when we complete the transcation -> index+2.



Code-:
int helper(vector<int>&prices,int buy,int index,int n)
{
        if(index>=n) return 0;
        if(buy)
        {
            int take=-prices[index]+helper(prices,0,index+1,n);
            int not_take=0+helper(prices,1,index+1,n);
            return max(take,not_take);
        }
        else
        {
            int sell=prices[index]+helper(prices,1,index+2,n);
            int not_sell=0+helper(prices,0,index+1,n);
            return max(sell,not_sell);
        }
}
int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int index=0;
        int buy=1;
        return helper(prices,buy,index,n);
}



Solution 2-:
Steps-:
1)using memo.

int helper( vector<vector<int>>&memo,vector<int>&prices,int buy,int index,int n)
{
        if(index>=n) return 0;
        if(memo[buy][index]!=-1) return memo[buy][index];
        if(buy)
        {
            int take=-prices[index]+helper(memo,prices,0,index+1,n);
            int not_take=0+helper(memo,prices,1,index+1,n);
            return memo[buy][index]=max(take,not_take);
        }
        else
        {
            int sell=prices[index]+helper(memo,prices,1,index+2,n);
            int not_sell=0+helper(memo,prices,0,index+1,n);
            return memo[buy][index]=max(sell,not_sell);
        }
}
int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int index=0;
        int buy=1;
        vector<vector<int>>memo(2,vector<int>(5001,-1));
        return helper(memo,prices,buy,index,n);
}


Solution 3-:
Steps-:
1)using tabulation.

Code-:
int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>>dp(2,vector<int>(n+2,0));
       
        for(int index=n-1;index>=0;index--)
        {
            for(int buy=0;buy<=1;buy++)
            {
                if(buy)
                {
                int take=-prices[index]+dp[0][index+1];
                int not_take=0+dp[1][index+1];
                dp[buy][index]=max(take,not_take);
                }
                else
                {
                  int sell=prices[index]+dp[1][index+2];
                  int not_sell=0+dp[0][index+1];
                  dp[buy][index]=max(sell,not_sell);
                 }
            }
        }
        return dp[1][0];
}



Solution 4-:
