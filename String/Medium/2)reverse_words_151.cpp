Code-:
string reverseWords(string s) {
        int n=s.length();
        string ans="";
        string str="";

        for(int i=0;i<n;i++)
        {
            if(s[i]==' ' and str!="")
            { 
                ans=str+' '+ans;
                str="";
            }
            else if(s[i]==' ')
            continue;
            else
            str+=s[i];
        }
        if(str!="")
        ans=str+' '+ans;
        ans.pop_back();
        return ans;
}