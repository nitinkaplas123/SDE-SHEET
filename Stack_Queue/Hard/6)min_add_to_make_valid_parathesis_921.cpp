Solution 1:


Time -> O(n)
Space ->O(n)
Code:
int minAddToMakeValid(string s) {
       int n=s.length();
       int c1=0;
       int ans=0;
       for(int i=0;i<n;i++)
       {
           if(s[i]=='(')
           c1++;
           else 
           {
               c1--;
               if(c1<0)
               {
                   ans++;
                   c1=0;
               }
           }
       }
       return ans+c1;
}