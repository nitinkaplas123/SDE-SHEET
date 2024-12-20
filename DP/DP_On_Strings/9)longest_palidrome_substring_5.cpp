Solution 1-:

Code-: Time->O(N^3)
bool isPalindrome(string str)
{
        int low=0;
        int high=str.length()-1;

        while(low<high)
        {
            if(str[low]!=str[high])
            return false;
            else
            {
                low++;
                high--;
            }
        }
        return true;
}

string longestPalindrome(string s) {
        int n=s.length();
        int start=0;
        int len=1;
        for(int i=0;i<n;i++)
        {
            for(int j=i;j<n;j++)
            {
                string str=s.substr(i,j-i+1);
                if(isPalindrome(str))
                {
                      if(len<j-i+1)
                      {
                         start=i;
                         len=j-i+1;
                      }
                }
            }
        }
        return s.substr(start,len);
}



Solution 2-:

Code-: Time->O(N^2)
string longestPalindrome(string s) {
        int n=s.length();
        int dp[n][n];
        for(int i=0;i<n;i++)
        {
            dp[i][i]=1;
        }
        
        int len=1;
        int start=0;
        for(int i=n-2;i>=0;i--)
        {
            for(int j=i+1;j<n;j++)
            {
                if(s[i]==s[j])
                {
                    if(j-i==1 || dp[i+1][j-1]==1)
                    {
                        dp[i][j]=1;
                        int curr_len=j-i+1;
                        if(curr_len>len)
                        {
                            len=curr_len;
                            start=i;
                        }
                    }
                    else
                    dp[i][j]=0;
                }
                else
                dp[i][j]=0;
            }
        }
        return s.substr(start,len);
}