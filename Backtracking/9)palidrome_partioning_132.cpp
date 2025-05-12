Solution 1-:
Steps-:
1)using same question of palindrome partitioning.

Code-:
bool isPalindrome(string &s)
{
        string s1=s;
        reverse(s.begin(),s.end());
        return (s1==s);
}
void helper(string s,int index,int n,vector<string>&v1,int &ans)
{
        if(index==n)
        {
            if(ans>v1.size()-1)
            ans=v1.size()-1;
            return ;
        }
        for(int i=index;i<n;i++)
        {
            string str=s.substr(index,i-index+1);
            if(isPalindrome(str))
            {
                v1.push_back(str);
                helper(s,i+1,n,v1,ans);
                v1.pop_back();
            }
        }
}
int minCut(string s) {
        vector<string>v1;
        int n=s.length();
        int ans=INT_MAX;
        helper(s,0,n,v1,ans);
        return ans;
}



Solution 2-:
Steps-:
1)


Code:

bool isPalindrome(string &s,int i,int j)
{
        while(i<j)
        {
            if(s[i]!=s[j]) return false;
            else
            {
                i++;
                j--;
            }
        }
        return true;
}
int helper(string &s,int index,int n)
{
        if(index==n)
        return 0;
        int minCuts=INT_MAX;
        int cuts=0;
        for(int i=index;i<n;i++)
        {
            if(isPalindrome(s,index,i))
            cuts=(1+helper(s,i+1,n));
            minCuts=min(minCuts,cuts);
        }
        return minCuts;
}
int minCut(string s) 
{
        int n=s.length();
        // int ans=helper(s,0,n);
        // return ans-1;

        vector<int>dp(n+1,0);
        dp[n]=0;

        for(int i=n-1;i>=0;i--)
        {
            int minCuts=INT_MAX;
            int cuts=0;
            int j;
            for(j=i;j<n;j++)
            {
                if(isPalindrome(s,i,j))
                {
                   cuts=1+dp[j+1];
                   minCuts=min(minCuts,cuts);
                }
            }
            dp[i]=minCuts;
        }
        return dp[0]-1;
}