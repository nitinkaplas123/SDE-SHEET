Solution 1-:
Steps-:
1)using recursion 
2)whenever we make a transaction -> prices[index]-fee is the profit.


Code-:
int helper(vector<int>&prices,int index,int buy,int fee,int n)
{
        if(index==n) return 0;

        if(buy)
        {
            int take=-prices[index]+helper(prices,index+1,0,fee,n);
            int not_take=0+helper(prices,index+1,1,fee,n);
            return max(take,not_take);
        } 
        else
        {
            int sell=prices[index]-fee+helper(prices,index+1,1,fee,n);
            int not_sell=0+helper(prices,index+1,0,fee,n);
            return max(sell,not_sell);
        }
}
int maxProfit(vector<int>& prices, int fee) {
        int n=prices.size();
        int index=0;
        int buy=1;
        return helper(prices,index,buy,fee,n);
}


Solution 2-:
Steps-:
1)using memo.

Code-:
int helper(int memo[2][50000],vector<int>&prices,int index,int buy,int fee,int n)
{
        if(index==n) return 0;
        if(memo[buy][index]!=-1) return memo[buy][index];

        if(buy)
        {
            int take=-prices[index]+helper(memo,prices,index+1,0,fee,n);
            int not_take=0+helper(memo,prices,index+1,1,fee,n);
            return memo[buy][index]=max(take,not_take);
        } 
        else
        {
            int sell=prices[index]-fee+helper(memo,prices,index+1,1,fee,n);
            int not_sell=0+helper(memo,prices,index+1,0,fee,n);
            return memo[buy][index]=max(sell,not_sell);
        }
}
int maxProfit(vector<int>& prices, int fee) {
        int n=prices.size();
        int index=0;
        int buy=1;
        int memo[2][50000];
        memset(memo,-1,sizeof(memo));
        return helper(memo,prices,index,buy,fee,n);
}



Solution 3-:
Steps-:
1)using tabulation.

Code-:
int maxProfit(vector<int>& prices, int fee) {
    int n=prices.size();
    vector<vector<int>>dp(2,vector<int>(n+1,0));
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
                int sell=prices[index]-fee+dp[1][index+1];
                int not_sell=0+dp[0][index+1];
                dp[buy][index]=max(sell,not_sell);
                }
            }
    }
    return dp[1][0];
}