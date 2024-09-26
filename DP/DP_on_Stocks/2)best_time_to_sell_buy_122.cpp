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
        int ans=0;
        int i=1;
        
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
                ans+=(sell-buy);
            }
            else
            i++;
        }
        return ans;
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