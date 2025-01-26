Solution 1-:
Steps-:
1)same as fibonacci series 

Time->O(N)
Space->O(N)
Code-:
int tribonacci(int n) {
        if(n==0 || n==1)
        return n;
        int dp[n+1];
        dp[0]=0;
        dp[1]=1;
        dp[2]=1;
        for(int i=3;i<=n;i++)
        {
            dp[i]=(dp[i-1]+dp[i-2]+dp[i-3]);
        }
        return dp[n];
}


Solution 2-:
Code-:
int tribonacci(int n) {
        if(n==0 || n==1)
        return n;
        
        int a=0;
        int b=1;
        int c=1;
        for(int i=3;i<=n;i++)
        {
            int d=a+b+c;
            a=b;
            b=c;
            c=d;
        }
        return c;
}