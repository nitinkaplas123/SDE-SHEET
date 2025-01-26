Solution 1-:
Steps-:
1)using brute force 

Time->O(N^2)
Code-:
int helper(string &str,bool flag)
{
       int n=str.length();
       int count=0;
       for(int i=0;i<n;i++)
       {
          if(flag==false)
          {
            if(str[i]=='0')
            count++;
          }
          else
          {
             if(str[i]=='1')
             count++;
          }
       }
       return count;
}
int maxScore(string s) {
        int n=s.length();
        int ans=0;
        for(int i=0;i<n-1;i++)
        {
            string s1=s.substr(0,i+1);
            string s2=s.substr(i+1,n-i-1);
            int val1=helper(s1,false);
            int val2=helper(s2,true);
            ans=max(ans,val1+val2);
        }
        return ans;
}


Solution 2-:
Steps-:
1)using pre_sum of zeros arrays 
  and   pre_sum of ones arrays 

Code-: Time->O(N) Space->O(N)
int maxScore(string s) {
        int n=s.length();        
        //zeros //ones array
        vector<int>zeros(n,0);
        vector<int>ones(n,0);
        if(s[0]=='0') zeros[0]=1;
        if(s[0]=='1') ones[0]=1;
        for(int i=1;i<n;i++)
        {
           if(s[i]=='0')
           zeros[i]=1+zeros[i-1];
           else
           zeros[i]=zeros[i-1];

           if(s[i]=='1')
           ones[i]=1+ones[i-1];
           else
           ones[i]=ones[i-1];
        }

        int ans=0;
        for(int i=0;i<n-1;i++)
        {
            int val1=zeros[i];
            int val2=ones[n-1]-ones[i];
            ans=max(ans,val1+val2);
        }
        return ans;
}



Solution 3-:
Steps-:
1)idea is using sol2 where we are using arrays 

Case0-: (totalOnes)
totalOnes++;

Case1-:(zeros)
currZeros++;

Case2-:(ones)
currOnes++;

answer-:
currZeros + (totalOnes-currOnes);


Code-: Time->O(N) Space->O(1)
int maxScore(string s) {
        int n=s.length();
        int zeros=0;
        int ones=0;
        int totalOnes=0;
        
        for(int i=0;i<n;i++)
        {
            if(s[i]=='1')totalOnes++;
        }
        
        int ans=0;
        for(int i=0;i<n-1;i++)
        {
           if(s[i]=='0')
           zeros++;
           else
           ones++;
           
           int val1=zeros;
           int val2=totalOnes-ones;
           ans=max(ans,val1+val2);
        }
        return ans;
}