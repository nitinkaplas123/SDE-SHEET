Steps-:
we need n opening and n closing and form all valid paratheis.
opening brackets-:
1)we add opening bracket when open<n.
closing brackets-:
1)we add closing bracket when open>close.

stopping case-:
1)when open=n and close==n means we make a valid parathesis 
  lets add it into vector of ans.

Catalan Number: (2n)!/(n+1)! n!
Code-:
void helper(int open,int close,string str,int n,vector<string>&ans)
{
        if(open==n and close==n)
        {
            ans.push_back(str);
            return ;
        }

        if(open<n)
        helper(open+1,close,str+"(",n,ans);
        if(close<open)
        helper(open,close+1,str+")",n,ans);
}

vector<string> generateParenthesis(int n) {
        vector<string>ans;
        int open=0;
        int close=0;
        string str="";
        helper(open,close,str,n,ans);
        return ans;
}