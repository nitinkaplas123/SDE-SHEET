Solution 1-:
Steps-:
1)using recursion
2)if(buy)
  {
    option1 -> buy it.
    option2 -> not buy it.
    return max(option1,option2);
  }
  else
  {
    option1 -> sell it.
    option2 -> not sell it.
    return max(option1,option2);
  }


Time-> O(2^n)
Code-:
int helper(vector<int>& prices,int index,int buy,int n)
{
        if(index==n) return 0;
        if(buy)
        {
            int take=-prices[index]+helper(prices,index+1,0,n);
            int not_take=0+helper(prices,index+1,1,n);
            return max(take,not_take);
        }
        else
        {
            int sell=prices[index]+helper(prices,index+1,1,n);
            int not_sell=0+helper(prices,index+1,0,n);
            return max(sell,not_sell);
        }
}
int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int index=0;
        int buy=1;
        return helper(prices,index,buy,n);
}


Solution 2-:
Steps-:
1)using memo. 

Time->O(N)
Space->O(N)
Code-:
int helper(int memo[2][30000],vector<int>& prices,int index,int buy,int n)
{
        if(index==n) return 0;
        if(memo[buy][index]!=-1) return memo[buy][index];

        if(buy)
        {
            int take=-prices[index]+helper(memo,prices,index+1,0,n);
            int not_take=0+helper(memo,prices,index+1,1,n);
            return memo[buy][index]=max(take,not_take);
        }
        else
        {
            int sell=prices[index]+helper(memo,prices,index+1,1,n);
            int not_sell=0+helper(memo,prices,index+1,0,n);
            return memo[buy][index]=max(sell,not_sell);
        }
}
int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int index=0;
        int buy=1;
        int memo[2][30000];
        memset(memo,-1,sizeof(memo));
        return helper(memo,prices,index,buy,n);
}


Solution 3-:
Steps-:
1)Using tabulation 
2) see in line 75 -> return f(buy,index) -> return dp[1][0]  -> buy=1 and index=0. 
3) create dp[2][n+1];
4) memo ->       starting from inded=0 to index=n 
   tabulation -> starting from index=n to index=0

5) Base case-:
   if(index==n) return 0;   =>either u buy or sell.  -> dp[0][n]=0 dp[1][n]=0.

6) for(int i=index-1;i>=0;i--)
   {
      two option -> buy or not buy.
      for(int buy=0;buy<=1;buy++)
      {
        if(buy)
        
        else 

      }
   }
Code-:
 int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int dp[2][n+1];
        dp[0][n]=0;
        dp[1][n]=0;

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
                int sell=prices[index]+dp[1][index+1];
                int not_sell=0+dp[0][index+1];
                dp[buy][index]=max(sell,not_sell);
               }
            }
        }
        return dp[1][0];
    }



Solution 4-:
Steps-:
1)relace dp array here 
2)dp[0][n]=0 dp[1][n]=0;
  now to fill 
  index=n-1 we want index+1 means just next 
  for both buy and not buy.
i=n-2    i=n-1  i=n
[]        []    [0]
[]        []    [0]
using n-1 index.

Code-:
int maxProfit(vector<int>& prices) {
          
        int n=prices.size();
        vector<int>prev(2,0);
        vector<int>curr(2,0);
        
        for(int index=n-1;index>=0;index--)
        {
            for(int buy=0;buy<=1;buy++)
            {
                if(buy)
                {
                 int take=-prices[index]+prev[0];
                 int not_take=0+prev[1];
                 curr[1]=max(take,not_take);
                }
               else
               {
                int sell=prices[index]+prev[1];
                int not_sell=0+prev[0];
                curr[0]=max(sell,not_sell);
               }
            }
            prev=curr;
        }
        return curr[1];
    }
Solution 1-:
Steps-:
Case1-:
if(prices[i]>prices[i-1])
buy the stock =prices[i-1]

Case2-:
when upward if condition is false.
means prices[i-1]>prices[i]

means we have to sell the stocks -:
sell=prices[i-1];

Code-:
int maxProfit(vector<int>& prices) {
       int n=prices.size();
       int buy=0;
       int sell=0;
       int i=1;
       int profit=0;
       while(i<n)
       {
          if(prices[i]>prices[i-1])
          {
            buy=prices[i-1];
            while(i<n and prices[i]>prices[i-1])
            {
                i++;
            }
            sell=prices[i-1];
            profit+=sell-buy;
          }
          else
          i++;
       }
       return profit;
}



Solution 2-:
int maxProfit(vector<int>& prices) {
        int max = 0;
        int start = prices[0];
        int len = prices.size();
        for(int i = 1;i<len; i++){
            if(start < prices[i]){
                max += prices[i] - start;
            }
            start = prices[i];
        }
        return max;
}





