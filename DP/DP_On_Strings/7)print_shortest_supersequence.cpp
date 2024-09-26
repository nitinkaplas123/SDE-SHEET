Solution 1-:
Steps-:
1)find lcs and print the lcs.
2)now you are having 3 strings str1,str2,lcs-string.
3)traverse it.


class Solution {
public:
    string helper2(string &str1,string &str2,string &str3,int n1,int n2)
    {
       string str="";
       int n3=str3.length();

       int i=0;
       int j=0;
       int k=0;
       while(i<n1 and j<n2 and k<n3)
       {
           if(str1[i]!=str3[k])
           {
              str.push_back(str1[i++]);
           }
           else if(str2[j]!=str3[k])
           {
             str.push_back(str2[j]);
             j++;
           }
           else
           {
               str.push_back(str3[k]);
               i++;
               j++;
               k++;
           }
       }

       while(i<n1)
       {
           str.push_back(str1[i++]);
       }

       while(j<n2)
       {
           str.push_back(str2[j++]);
       }
       return str;
    }
    void helper(string &res,int dp[1001][1001],int n,int m,string &s1,string &s2)
    {
        int i=n;
        int j=m;

        while(i>0 and j>0)
        {
            if(s1[i-1]==s2[j-1])
            {
                res+=s1[i-1];
                i--;
                j--;
            }
            else if(dp[i-1][j]>dp[i][j-1])
            {
                i--;
            }
            else
            j--;
        }
       
    }
    string shortestCommonSupersequence(string str1, string str2) {
        int n=str1.size();
        int m=str2.size();
        int dp[1001][1001];
        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=m;j++)
            {
                if(i==0 || j==0)
                dp[i][j]=0;
                else if(str1[i-1]==str2[j-1])
                dp[i][j]=1+dp[i-1][j-1];
                else
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }

        string res="";
        helper(res,dp,n,m,str1,str2);
        reverse(res.begin(),res.end());
        string lca=res;

        return helper2(str1,str2,lca,n,m);
    }
};