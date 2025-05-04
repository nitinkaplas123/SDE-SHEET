Solution 1:
Steps:
1)Using recursion.

2) Cuts vector 
  1. add 0 in front of vector.
  2. add n in last of vector 
 This 0 and n is helping for calculating the cost of the cut. 

3) Make sure cuts array is sorted.
   because when we mark the cut at suppose 4 position 
    0 1 2 3 4 5
   [0,1,3,4,5,7]

   i=1 j=4 

   suppose we make a cut at 4 
   cost=7   -> cuts[j+1]-cuts[i-1].

 [1,2,3]             [5,6,7]

 now when 4 is solved then we can explicity solved all the cuts f(0,3) 
 similarily we can solved all the cuts in the right side as well. 

 so thats why we have to sort the cuts so that cuts values lies in left stick f(i,index-1)
                                               cuts values lies in right stick f(index+1,j)




Time -> Expo
int helper(vector<int>&cuts,int i,int j,int n)
{
        if(i>j) return 0;
        int ans=INT_MAX;
        for(int index=i;index<=j;index++)
        {
           int cost=cuts[j+1]-cuts[i-1];
           int val1=helper(cuts,i,index-1,n);
           int val2=helper(cuts,index+1,j,n);
           ans=min(ans,cost+val1+val2);
        }
        return ans;
}
int minCost(int n, vector<int>& cuts) {
        int size=cuts.size();
        cuts.insert(cuts.begin(),0);
        cuts.push_back(n);

        sort(cuts.begin(),cuts.end());
        return helper(cuts,1,size,n);
}



Solution 2:
Steps:
1)Using memo

Code:
int helper(int memo[101][101],vector<int>&cuts,int i,int j,int n)
{
        if(i>j) return 0;
        if(memo[i][j]!=-1) return memo[i][j];
        int ans=INT_MAX;
        for(int index=i;index<=j;index++)
        {
           int cost=cuts[j+1]-cuts[i-1];
           int left=helper(memo,cuts,i,index-1,n);
           int right=helper(memo,cuts,index+1,j,n);
           ans=min(ans,cost+left+right);
        }
        return memo[i][j]=ans;
}
int minCost(int n, vector<int>& cuts) {
        int size=cuts.size();
        cuts.insert(cuts.begin(),0);
        cuts.push_back(n);

        sort(cuts.begin(),cuts.end());
        int memo[101][101];
        memset(memo,-1,sizeof(memo));
        return helper(memo,cuts,1,size,n);
}



Solution 3:
Steps-:
1)Using tabulation 

Code:
int minCost(int n, vector<int>& cuts) {
        int size=cuts.size();
        cuts.insert(cuts.begin(),0);
        cuts.push_back(n);

        sort(cuts.begin(),cuts.end());
        // int memo[101][101];
        // memset(memo,-1,sizeof(memo));
        // return helper(memo,cuts,1,size,n);
        
        vector<vector<int>>dp(size+2,vector<int>(size+2,0));
        for(int i=size;i>=1;i--)
        {
            for(int j=1;j<=size;j++)
            {
                if(i>j) continue;
                int ans=INT_MAX;
                for(int index=i;index<=j;index++)
                {
                  int cost=cuts[j+1]-cuts[i-1];
                  int left=dp[i][index-1];
                  int right=dp[index+1][j];
                  ans=min(ans,cost+left+right);
                }
                dp[i][j]=ans;
            }
        }
        return dp[1][size];
}



Java :


Solution 1:
import java.util.*;

public class Solution {
    public static int helper(List<Integer> cuts, int i, int j) {
        if (i > j) return 0;
        int ans = Integer.MAX_VALUE;

        for (int index = i; index <= j; index++) {
            int cost = cuts.get(j + 1) - cuts.get(i - 1);
            int val1 = helper(cuts, i, index - 1);
            int val2 = helper(cuts, index + 1, j);
            ans = Math.min(ans, cost + val1 + val2);
        }
        return ans;
    }

    public static int minCost(int n, int[] cutArr) {
        List<Integer> cuts = new ArrayList<>();
        for (int cut : cutArr) cuts.add(cut);

        // Add the boundaries
        cuts.add(0);
        cuts.add(n);
        Collections.sort(cuts);

        return helper(cuts, 1, cuts.size() - 2);  // size-2 because last index is cuts.size()-1
    }
}



Solution 2:

import java.util.*;

public class Solution {
    public static int helper(int[][] memo, List<Integer> cuts, int i, int j) {
        if (i > j) return 0;
        if (memo[i][j] != -1) return memo[i][j];

        int ans = Integer.MAX_VALUE;
        for (int index = i; index <= j; index++) {
            int cost = cuts.get(j + 1) - cuts.get(i - 1);
            int left = helper(memo, cuts, i, index - 1);
            int right = helper(memo, cuts, index + 1, j);
            ans = Math.min(ans, cost + left + right);
        }

        return memo[i][j] = ans;
    }

    public static int minCost(int n, int[] cutArr) {
        List<Integer> cuts = new ArrayList<>();
        for (int cut : cutArr) cuts.add(cut);

        cuts.add(0);
        cuts.add(n);
        Collections.sort(cuts);

        int size = cutArr.length;
        int[][] memo = new int[101][101];
        
        // Fill memo with -1
        for (int[] row : memo) {
            Arrays.fill(row, -1);
        }

        return helper(memo, cuts, 1, size);
    }
}
