Solution -:
Steps-:
1)Find the lcs.
2)int insert=n1-lcs. (this is the number of steps we have to insert to make whole string plaidrome)

int longestCommonSubsequence(string text1, string text2) {
        int n1=text1.length();
        int n2=text2.length();
        // int dp[n1+1][n2+1];
        vector<int>curr(n2+1,0);
        vector<int>prev(n2+1,0);
        for(int i=1;i<=n1;i++)
        {
            for(int j=1;j<=n2;j++)
            {
                if(text1[i-1]==text2[j-1])
                curr[j]=1+prev[j-1];
                else
                curr[j]=max(curr[j-1],prev[j]);
            }
            prev=curr;
        }
        return prev[n2];
    }
    int minInsertions(string s) {
        int n=s.length();
        string s1=s;
        reverse(s.begin(),s.end());
        int lcs=longestCommonSubsequence(s1,s);
        return n-lcs;
    }