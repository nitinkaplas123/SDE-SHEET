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

