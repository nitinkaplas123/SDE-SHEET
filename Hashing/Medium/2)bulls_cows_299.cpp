Solution 1-:
Steps-:
1)bulls -> matching s[i]==g[i];
2)cows  -> not matching but g[i] is present in s string but not at correct place. 

3) count bulls and count cows.
4) return bulls+"A"+cows+"B"


Time -> O(n)
Space-> O(n)
Code-:
string getHint(string s, string g) {
        int n1=s.length();
        int n2=g.length();
        unordered_map<int,int>m;
        int bulls=0;
        for(int i=0;i<n1;i++)
        {
            if(s[i]==g[i])
            bulls++;
            else
            m[s[i]-'0']++;
        }

        int cows=0;
        for(int i=0;i<n2;i++)
        {
            if(s[i]!=g[i])
            {
                int val=g[i]-'0';
                if(m[val]>0)
                {
                    cows++;
                    m[val]--;
                }
            }
        }
        string ans="";
        ans+=to_string(bulls);
        ans+="A";
        ans+=to_string(cows);
        ans+="B";
        return ans;
}