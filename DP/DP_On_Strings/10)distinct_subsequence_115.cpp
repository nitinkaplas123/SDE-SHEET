Solution 1-:
Steps-:
1)Case1 -:
  If the s[i]==t[j]
  {
     matches     -> (i+1,j+1)
     not_matches -> (i+1,j)   -> here j is not ready to match -> j said yeah I index i pls search sometime like similar  
  }
2)Case2-:
  not macthes s[i]!=t[j]
  (i+1,j)

3)Base case -:
  when j is out of bound -> whole string matches -> return 1. 
  when i is out of bound -> string is not matches -> return 0.


Code-:
int helper(string s,string t,int i,int j,int n1,int n2)
{
        if(j==n2) return 1;
        if(i==n1) return 0;

        if(s[i]==t[j])
        {
            int take=helper(s,t,i+1,j+1,n1,n2);
            int not_take= helper(s,t,i+1,j,n1,n2);
            return take+not_take;
        }
        else
        return helper(s,t,i+1,j,n1,n2);
}

int numDistinct(string s, string t) {
        int n1=s.length();
        int n2=t.length();
        
        return helper(s,t,0,0,n1,n2);
}


or -:

Code-: (from back)
int helper(string &s,string &t,int n1,int n2)
{
        if(n2==0) return 1;
        if(n1==0) return 0;
        if(s[n1-1]==t[n2-1])
        return helper(s,t,n1-1,n2-1) + helper(s,t,n1-1,n2);
        else
        return helper(s,t,n1-1,n2);
}
int numDistinct(string s, string t) {
        int n1=s.length();
        int n2=t.length();
        return helper(s,t,n1,n2);
}


Solution 2-:
Steps-:
1)using memo 

int helper(vector<vector<int>>&memo,string &s,string &t,int i,int j,int n1,int n2)
{
        if(j==n2) return 1;
        if(i==n1) return 0;
        if(memo[i][j]!=-1) return memo[i][j];
        
       
        if(s[i]==t[j])
        {
            int take=helper(memo,s,t,i+1,j+1,n1,n2);
            int not_take= helper(memo,s,t,i+1,j,n1,n2);
            return memo[i][j]=take+not_take;
        }
        else
        return memo[i][j]=helper(memo,s,t,i+1,j,n1,n2);
}
int numDistinct(string s, string t) {
        int n1=s.length();
        int n2=t.length();
        vector<vector<int>>memo(n1+1,vector<int>(n2+1,-1));
        return helper(memo,s,t,0,0,n1,n2);
}



Solution 3-:
Steps-:
1)using tabulation 

int mod=1e9;
int numDistinct(string s, string t) {
        int n1=s.length();
        int n2=t.length();
        // return helper(s,t,n1,n2);
        vector<vector<int>>dp(n1+1,vector<int>(n2+1,0));

        for(int i=0;i<=n1;i++)
        {
            for(int j=0;j<=n2;j++)
            {
                if(j==0)      
                dp[i][j]=1;
                else if(i==0) 
                dp[i][j]=0;
                else if(s[i-1]==t[j-1])
                dp[i][j]=(dp[i-1][j-1]+dp[i-1][j])%mod;
                else
                dp[i][j]=dp[i-1][j];
            }
        }
        return dp[n1][n2];
}



Solution 4-:
Steps-:
1)space optimised. 


Code-:
int mod=1e9;
int numDistinct(string s, string t) {
        int n1=s.length();
        int n2=t.length();
        // return helper(s,t,n1,n2);
        vector<int>prev(n2+1);
        vector<int>curr(n2+1);

        for(int i=0;i<=n1;i++)
        {
            for(int j=0;j<=n2;j++)
            {
                if(j==0)      
                curr[j]=1;
                else if(i==0) 
                curr[j]=0;
                else if(s[i-1]==t[j-1])
                curr[j]=(prev[j-1]+prev[j])%mod;
                else
                curr[j]=prev[j];
            }
            prev=curr;
        }
        return curr[n2];
}