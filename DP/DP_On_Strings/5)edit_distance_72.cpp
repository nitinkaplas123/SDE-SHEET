
Testcase -:
s="horse"
t="ros"

Solution 1-:
Steps-:
1)Using recusrion 

Code-:
int helper(string s,string t,int n1,int n2)
{
        if(n1==0)
        return n2;
        if(n2==0) 
        return n1;
        
        if(s[n1-1]==t[n2-1])
        return helper(s,t,n1-1,n2-1);
        else
        return 1+min(helper(s,t,n1,n2-1), // insert  
                 min(helper(s,t,n1-1,n2), // delete 
                     helper(s,t,n1-1,n2-1)));// replace 
}

int editDistance(string s, string t) {
     
}


Solution 2-:

Code-:
int helper(int memo[101][101],string s,string t,int n1,int n2)
    {
        if(n1==0)
        return n2;
        if(n2==0)
        return n1;
        if(memo[n1][n2]!=-1)
        return memo[n1][n2];
        
        int res;
        
        if(s[n1-1]==t[n2-1])
        res= helper(memo,s,t,n1-1,n2-1);
        else
        res=1+min(helper(memo,s,t,n1,n2-1),
                 min(helper(memo,s,t,n1-1,n2),
                     helper(memo,s,t,n1-1,n2-1)));
        return memo[n1][n2]=res;
    }
    int editDistance(string s, string t) {
       int n1=s.length();
       int n2=t.length();
       int memo[101][101];
       memset(memo,-1,sizeof(memo));
       return helper(memo,s,t,n1,n2);
    }

