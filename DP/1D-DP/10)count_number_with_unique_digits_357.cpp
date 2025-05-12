Solution 1:

1)n=0 

0<=x< 1
num=0

o/p -: 1

2)n=1

0<=x<10

0 to 9 all are unique.

o/p -: 10

3)n=2

0<=x<100

1digits -> 0 to 9   -> already calculated which is 10
2 digits ->10 to 99 -> 

1st place -> 0 to 9 -> we can write anything except 0 beacuse it makes no sense starting number with zero.
2nd place -> 0 to 9 -> we can start with any number also with zero but not with that number which is used in 1st place.

tenths place                     ones place 
9 options (except zero)           9 options (except which we used at hundredth place)

combination -> 9*9 -> 81 


1 digits -> 10 
2 digits -> 81

total 0 to 99 -> 91 


4) n=3

hundred            tenth    ones 
9 (except 0)       9        8 (except 2 number which we used at hundred and tenth place)   0 to 9 -> 10 -2 =8

9*9*8=648 

1 digits -> 10 
2 digits -> 81
3 digits -> 648 


total 0 to 999 -> 739


so on...


Time -> O(N^2)
Space ->O(N)

Code:
int countNumbersWithUniqueDigits(int n) {
        int dp[9];
        dp[0]=1;
        dp[1]=10;
        for(int i=2;i<=n;i++)
        {
            int num=1;
            for(int j=1;j<=i;j++)
            {
                 if(j<=2)
                 num*=9;
                 else
                 num*=(9-j+2);
            }
            dp[i]=dp[i-1]+num;
        }
        return dp[n];
}


Solution 2:
Time -> O(N^2)
Space ->O(1)

int countNumbersWithUniqueDigits(int n) {
        int prev=1;
        for(int i=1;i<=n;i++)
        {
            int curr=1;
            int num=1;
            for(int j=1;j<=i;j++)
            {
                 if(j<=2)
                 num*=9;
                 else
                 num*=(9-j+2);
            }
            curr=prev+num;
            prev=curr;
        }
        return prev;
}



Solution 3:

By seeing the pattern 

n=1 -> 9 
n=2 -> 9 * 9 
n=3 -> 9 * 9 * 8
n=4 -> 9 * 9 * 8 * 7

so on.....

till prev result will be stored in result variable.

current -> will be calculate in current variable.



Time Complexity : O(N)
Space -> O(1)


Code:
int countNumbersWithUniqueDigits(int n) {
        if(n==0) return 1;
        if(n==1) return 10;

        int result=10;
        int curr=9;

        for(int i=2;i<=n;i++)
        {
            curr*=(10-(i-1));
            result+=curr;
        }
        return result;
}