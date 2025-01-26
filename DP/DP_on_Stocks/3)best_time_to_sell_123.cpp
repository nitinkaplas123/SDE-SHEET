Solution 1-:
Steps-:
1)using recursion.
2)using same idea of infinite transcation -> here we have a cap of 2.


Code-:
int helper(vector<int>&prices,int index,int buy,int n,int cap)
{
        if(cap==0 || index==n) return 0;
        if(buy)
        {
            int take=-prices[index]+helper(prices,index+1,0,n,cap);
            int not_take=0+helper(prices,index+1,1,n,cap);
            return max(take,not_take);
        }
        else
        {
            int sell=prices[index]+helper(prices,index+1,1,n,cap-1);
            int not_sell=0+helper(prices,index+1,0,n,cap);
            return max(sell,not_sell);
        }
}
int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int index=0;
        int buy=1;
        return helper(prices,index,buy,n,2);
}


Solution 2-:
Steps-:
1) Using memo.
2) buy=> yes/no -> [2]
3) cap=2 -> either 0/1/2 -> no transcation, one transaction, two transaction -> because question said atmost 2. [3]
4) base case-:
   1. if (index==n)  return 0.
   2. if (cap==0)    return 0.

int helper(int memo[2][3][100000],vector<int>&prices,int index,int buy,int n,int cap)
{
        if(cap==0 || index==n) return 0;
        if(memo[buy][cap][index]!=-1) return memo[buy][cap][index];
        
        if(buy)
        {
            int take=-prices[index]+helper(memo,prices,index+1,0,n,cap);
            int not_take=0+helper(memo,prices,index+1,1,n,cap);
            return memo[buy][cap][index]=max(take,not_take);
        }
        else
        {
            int sell=prices[index]+helper(memo,prices,index+1,1,n,cap-1);
            int not_sell=0+helper(memo,prices,index+1,0,n,cap);
            return memo[buy][cap][index]=max(sell,not_sell);
        }
}
int maxProfit(vector<int>& prices) 
{
        int n=prices.size();
        int index=0;
        int buy=1;
        int memo[2][3][100000];
        memset(memo,-1,sizeof(memo));
        return helper(memo,prices,index,buy,n,2);
}



Solution 3-:
Steps-:
1)Using tabulation.

Code-:
int maxProfit(vector<int>& prices) 
{
        int n=prices.size();
        
        int dp[2][3][n+1];
        for(int index=0;index<=n;index++)
        {
            for(int buy=0;buy<=1;buy++)
            {
                dp[buy][0][index]=0;
            }
        }

        for(int buy=0;buy<=1;buy++)
        {
            for(int cap=0;cap<=2;cap++)
            {
                dp[buy][cap][n]=0;
            }
        }
        for(int index=n-1;index>=0;index--)
        {
            for(int cap=1;cap<=2;cap++)
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
        return dp[1][2][0];
}



Solution 4-:
Steps-:
1)space optimisation. 
2) prev and curr -> [2][3] vector for 2 -> buy and 3-> cap

Code-:
int maxProfit(vector<int>& prices) 
    {
        int n=prices.size();
        vector<vector<int>>prev(2,vector<int>(3,0));
        vector<vector<int>>curr(2,vector<int>(3,0));

        for(int index=n-1;index>=0;index--)
        {
            for(int cap=1;cap<=2;cap++)
            {
                for(int buy=0;buy<=1;buy++)
                {
                     if(buy)
                     {
                        //dp[0][cap][index+1];
                      int take=-prices[index]+prev[0][cap];
                      //dp[1][cap][index+1];
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
        return curr[1][2];
}



This function calculates the maximum profit from buying and selling stocks on different days, allowing for two transactions: one for buying and one for selling. Let’s break down the code step by step.

### Input
- `prices`: A vector of integers representing the price of a stock on different days.

### Overview
The algorithm finds the maximum profit by:
1. Calculating potential profits from one transaction (buying and then selling) on the left side.
2. Calculating potential profits from one transaction on the right side.
3. Combining these results to find the best possible profit from two transactions.

### Code Explanation

1. **Initialization:**
   ```cpp
   int n = prices.size();
   int left[n];  // Stores max profit up to each day from the left
   int right[n]; // Stores max profit from each day to the end
   left[0] = 0;  // No profit on the first day
   right[n-1] = 0; // No profit on the last day
   ```

2. **Calculate Left Profit Array:**
   - This loop calculates the maximum profit you can achieve from the beginning of the price array to each day `i`:
   ```cpp
   int lmin = prices[0]; // Minimum price so far
   for (int i = 1; i < n; i++) {
       left[i] = max(left[i-1], prices[i] - lmin); // Max profit up to day i
       lmin = min(lmin, prices[i]); // Update minimum price so far
   }
   ```

   - For each day `i`, the profit is calculated as the difference between the current price and the lowest price encountered so far (`lmin`). The `left[i]` keeps track of the maximum profit obtainable up to that day.

3. **Calculate Right Profit Array:**
   - This loop calculates the maximum profit from each day to the end of the price array:
   ```cpp
   int rmax = prices[n-1]; // Maximum price so far (from the right)
   for (int i = n - 2; i >= 0; i--) {
       right[i] = max(right[i + 1], rmax - prices[i]); // Max profit from day i to end
       rmax = max(rmax, prices[i]); // Update maximum price so far
   }
   ```

   - For each day `i`, the profit is calculated as the difference between the maximum price encountered so far (`rmax`) and the current price. The `right[i]` keeps track of the maximum profit obtainable from day `i` to the end.

4. **Combining Results:**
   ```cpp
   int profit = left[n - 1]; // Start with the best single transaction profit
   for (int i = 1; i < n; i++) {
       profit = max(profit, left[i - 1] + right[i]); // Combine profits
   }
   ```

   - The final profit is determined by checking all possible combinations of the profits from the `left` and `right` arrays. It considers the profit from one transaction up to day `i-1` and the profit from another transaction starting from day `i`.

5. **Return the Result:**
   ```cpp
   return profit;
   ```

### Summary
The function efficiently calculates the maximum profit that can be achieved with two transactions by using dynamic programming to track potential profits from the left and right sides of the price array. The overall time complexity is O(n), making it suitable for larger datasets.




Steps-:
1)Make a left array which stores the max profit from left to right.
 int left[n];
 left[0]=0;
 *Calculate Left Profit Array:**
   - This loop calculates the maximum profit you can achieve from the beginning of the price array to each day ith day.
   int lmin = prices[0]; // Minimum price so far
   for (int i = 1; i < n; i++) {
       left[i] = max(left[i-1], prices[i] - lmin); // Max profit up to day i
       lmin = min(lmin, prices[i]); // Update minimum price so far
   }

2)Make a right array which store the max profit from right to left.
   int right[n]; // Stores max profit from each day to the end
   right[n-1] = 0; // No profit on the last day
    int rmax = prices[n-1]; // Maximum price so far (from the right)
   for (int i = n - 2; i >= 0; i--) {
       right[i] = max(right[i + 1], rmax - prices[i]); // Max profit from day i to end
       rmax = max(rmax, prices[i]); // Update maximum price so far
   }

3)Now run a loop and store the max profit when we are divided the array into 2 parts 
  where we take the (max1 profit from left[i-1] + max2 profit from right[i])
  update the answer accordingly.

   int profit = left[n - 1]; // Start with the best single transaction profit
   for (int i = 1; i < n; i++) {
       profit = max(profit, left[i - 1] + right[i]); // Combine profits
   }
   return profit;

Code-:

int maxProfit(vector<int>& prices) 
{
        int n=prices.size();
        int left[n];
        int right[n];
        left[0]=0;
        right[n-1]=0;
        int lmin=prices[0];
        for(int i=1;i<n;i++)
        {
            left[i]=max(left[i-1],prices[i]-lmin);
            lmin=min(lmin,prices[i]);
        }

        int rmax=prices[n-1];
        for(int i=n-2;i>=0;i--)
        {
            right[i]=max(right[i+1],rmax-prices[i]);
            rmax=max(rmax,prices[i]);
        }
      
         int ans=max(right[0],left[n-1]);
         for(int i=1;i<n;i++)
         {
            ans=max(ans,left[i-1]+right[i]);
         }
         return ans;
}