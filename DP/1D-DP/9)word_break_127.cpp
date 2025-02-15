Solution 1-:
Steps-:
1)using recursion


Code-:
bool helper(string &s,int pos,int n, unordered_set<string>&set)
{
        if(pos==n) return true;
        for(int i=pos;i<n;i++)
        {
            string str=s.substr(pos,i-pos+1);
            if(set.find(str)!=set.end() and helper(s,i+1,n,set))
            return true;
        }
        return false;
}
bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string>set;
        for(int i=0;i<wordDict.size();i++)
        {
            set.insert(wordDict[i]);
        }
        return helper(s,0,s.length(),set);
}



Solution 2-:
Steps-:
1)using memo 
2)avoid substr string to save time.

Time->O(N^2)
Space->O(N)
Code-:
bool helper(int memo[301],string &s,int pos,int n, unordered_set<string>&set)
{
        if(pos==n) return true;
        if(memo[pos]!=-1) return memo[pos];
        string str="";
        for(int i=pos;i<n;i++)
        {
            // string str=s.substr(pos,i-pos+1);
            str+=s[i];
            if(set.find(str)!=set.end() and helper(memo,s,i+1,n,set))
            return memo[pos]=true;
        }
        return memo[pos]=false;
}
bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string>set;
        int memo[301];
        memset(memo,-1,sizeof(memo));
        for(int i=0;i<wordDict.size();i++)
        {
            set.insert(wordDict[i]);
        }
        return helper(memo,s,0,s.length(),set);
}


Solution 3-:
Steps-:
1)using tabulation

Code-:

bool wordBreak(string s, vector<string>& wordDict) {
        int n=s.length();
        unordered_set<string>set;
        for(int i=0;i<wordDict.size();i++)
        {
            set.insert(wordDict[i]);
        }
      
        vector<bool> dp(n + 1, false);
        dp[n] = true; 
        for(int i=n-1;i>=0;i--)
        {
            string str="";
            for(int j=i;j<n;j++)
            {
                str+=s[j];
                if(set.find(str)!=set.end() and dp[j+1])
                {
                   dp[i]=true;
                   break;
                }
            }
        }
        return dp[0];
}