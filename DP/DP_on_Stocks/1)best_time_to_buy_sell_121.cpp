Solution 1-:
Time->O(n^2)

Code-:
class Solution {
    public int maxProfit(int[] prices) {
        int profit = 0;
        int n = prices.length;
        
        for (int i = 0; i < n; i++) {
            int buy = prices[i];
            for (int j = i + 1; j < n; j++) {
                int sell = prices[j];
                profit = Math.max(profit, sell - buy);
            }
        }
        return profit;
    }
}


Code-:
int maxProfit(std::vector<int>& prices) {
        int buy = prices[0];
        int profit = 0;
        for (int i = 1; i < prices.size(); i++) 
        {
            if (prices[i] < buy) {
                buy = prices[i];
            } else if (prices[i] - buy > profit) {
                profit = prices[i] - buy;
            }
        }
        return profit;
}
