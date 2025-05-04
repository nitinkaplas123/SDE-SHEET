Given an array arr[] which represents the dimensions of a sequence of matrices where the ith matrix has the dimensions (arr[i-1] x arr[i]) for i>=1, find the most efficient way to multiply these matrices together. The efficient way is the one that involves the least number of multiplications.

Examples:

Input: arr[] = [2, 1, 3, 4]
Output: 20
Explanation: There are 3 matrices of dimensions 2 × 1, 1 × 3, and 3 × 4, Let this 3 input matrices be M1, M2, and M3. There are two ways to multiply: ((M1 x M2) x M3) and (M1 x (M2 x M3)), note that the result of (M1 x M2) is a 2 x 3 matrix and result of (M2 x M3) is a 1 x 4 matrix. 
((M1 x M2) x M3)  requires (2 x 1 x 3) + (2 x 3 x 4) = 30 
(M1 x (M2 x M3))  requires (1 x 3 x 4) + (2 x 1 x 4) = 20. 
The minimum of these two is 20.
Input: arr[] = [1, 2, 3, 4, 3]
Output: 30
Explanation: There are 4 matrices of dimensions 1 × 2, 2 × 3, 3 × 4, 4 × 3. Let this 4 input matrices be M1, M2, M3 and M4. The minimum number of multiplications are obtained by ((M1 x M2) x M3) x M4). The minimum number is (1 x 2 x 3) + (1 x 3 x 4) + (1 x 4 x 3) = 30.
Input: arr[] = [3, 4]
Output: 0
Explanation: As there is only one matrix so, there is no cost of multiplication.




A matrix -> []2*1     B matrix ->[]1*3    -> Resultant matrix -> []2*3

How many multiplications -> 2*1*3   (1 is the common)



  
  
  0 1 2 3
 [2,1,3,4]

 M1=(2*1) 
 M2=(1*3)
 M3=(3*4)
 

 K=1 to K=2

 1)k=1  -> (M1)*(M2*M3) 
           [20]

 2)K=2 ->   (M1*M2)*M3
       -> 30


O/P -: 20

 means 2 cut 

 1)k=1 

 M1*(M2*M3) 

 (M1) * (M2*M3) 
 (2*1) * (1*4)  => (2*1*4) ->    arr[i-1]*arr[k]*arr[j]

     1.M1 -> single -> 0    -> f(i,k) -> f(1,1) -> 0 

     2. (M2*M3)  [1*3]   [3*4]    -> f(k+1,j) -> f(2,3)   -> [1*3] [3*4] -> [1*3*4] => 12

        multiplication -> [1*3*4] -> 12    -> [1*3] [3*4] -> [1*3*4] => 12
        result matrix  -> [1*4]

     3. (M1) * (M2*M3)   -> arr[i-1]*arr[k]*arr[j]
        [2*1] * [1*4]
        [2*1*4]
        [8]

     0 + 12 + 8 
     20

 2) K=2 
    
    (M1*M2)*M3

    1. (M1*M2) (2*1) (1*3)
       
        multiplication -> [2*1*3]  -> 6
        result matrix  -> [2*3]

    2. M3 => 0 

    3. (M1*M2) * (M3)
        [2*3]  * [3*4]
        [2*3*4] -> 24

    Addition -> 6+0+24 
             -> 30 


min(20,30)

-> 20.

 
        0  1  2  3  4 
arr -> [10,20,30,40,50]
There are n-1 matrixs.

1) 1st -> [10,20]   10*20
2) 2nd -> [20,30]   20*30
3) 3rd -> [30,40]   30*40
4) 4th -> [40,50]   40*50

   ith -> arr[i-1]*arr[i]


Partition DP 

Rules-:
1)Always start with entire array/block. f(i,j)
  where i is the starting point.
  where j is the ending point.

  eg. (ABCD)
     i j     i j          i,j    i  j        i   j   i,j
  1)(A,B) * (C,D)      2) (A) * (BCD)     3)(A*B*C) *(D)

  
2)Try out all the partition.
  run a loop to try out all the partition.

3)Return the best possible two partition.  ( 1) or 2) or 3)) see line 22.

       0  1  2  3  4
arr-> [10,20,30,40,50]
          A  B  C  D 

A -> [10,20]
B -> [20,30]
C -> [30,40]
D -> [40,50]
   
   -> A[i-1]*A[i]


f(1,4) -> return the min multiplication to multiply from 1 to 4.


f(1,n-1).

          i        j 
       0  1  2  3  4
arr-> [10,20,30,40,50]
          A  B  C  D 

1) k   -> (i,j-1).  (1,3)
   
       -> f(i,k) , f(k+1,j)
   k=1 -> f(1,1) , f(2,4)

          (A) , (B*C*D)

   k=2 => f(1,2) , f(3,4)
          (A*B) , (C*D)

   k=3 => f(1,3) , f(4,4)
          (A*B*C) , (D)



Base case -:
suppose we have 1 element can we make a matrix ? 
[1]

no in this case both i and j are pointing to same.
if(i==j)
return 0.


          k 
          i        j 
       0  1  2  3  4
arr-> [10,20,30,40,50]
          A  B  C  D 


k=1 (A) *      (B*C*D)
    (10*20) *  ((20*30) (30*40) (40*50)) 
                (20*30) (30*50)
    (10*20)             (20*50)

    (10*20*50)

    A[i-1] * A[k] * A[j]    + f(i,k) + f(k+1,j)

     10*20*50 +  f(1,1) + f(2,4)
     10*20*50 +  f(A)   + f(B*C*D)
     10000    +  0       + f(B*C*D)

      
      f(B*C*D)
       k 
       i      j 
      [30,40,50]    
       B  C  D

      f(i,k)  + f(k+1,j)
      f(B)    + f(C,D)
       0      + f(40,50)

    

          k 
       i      j 
      [30,40,50]

     f(30,40) + f(50,50)


Solution 1-:
Steps-:
1)Using recursion.

Time Complexity -: exponential 

Code-:
int helper(vector<int>&arr,int i,int j)
{
        if(i==j) return 0;
        int ans=INT_MAX;
        for(int k=i;k<=j-1;k++)
        {
            int val=arr[i-1]*arr[k]*arr[j] + helper(arr,i,k) + helper(arr,k+1,j);
            ans=min(ans,val);
        }
        return ans;
}
int matrixMultiplication(vector<int> &arr) {
        int n=arr.size();
        return helper(arr,1,n-1);
}




 0  1  2  3  4 
[10,20,30,40,50]
    A  B  C  D 

    i        j 
Outer loop. -> i=1 j=n-1.
Inner loop  -> k=i to k=j-1.

why k=j-1 because 

if k=j 

f(i,k) f(k+1,j)  here k+1 is out of bound.



Solution 2-:
Steps-:
1)Using memo.

Time Complexity -: O(N^3)
Since there are O(n²) subproblems, and each takes O(n) time (due to the loop over k), the overall complexity is:O(N^3)


Code-:
int helper(int memo[101][101],vector<int>&arr,int i,int j)
{
        if(i==j) return 0;
        if(memo[i][j]!=-1) return memo[i][j];
       
        int ans=INT_MAX;
        for(int k=i;k<=j-1;k++)
        {
            int val=arr[i-1]*arr[k]*arr[j] + helper(memo,arr,i,k) + helper(memo,arr,k+1,j);
            ans=min(ans,val);
        }
        return memo[i][j]=ans;
}
int matrixMultiplication(vector<int> &arr) {
        int n=arr.size();
        int memo[101][101];
        memset(memo,-1,sizeof(memo));
        return helper(memo,arr,1,n-1);
}


Solution 3-:
Steps:
1)Tabulation 


Case1-:
Base Case-:
f(1,1) -> 0 
f(2,2) -> 0

for(i=0;i<n;i++)
{
    dp[i][i]=0;
}

Case2-:
in recursion (i=1 to i=n-1) see in comments 
in tabulation -> reverse it.

for(int i=n-1;i>=1;i--)


Case3-:

in recursion (j=n-1 to i=1) see in comments 
in tabulation -> reverse it 
for(int j=1;j<=n-1;j++)


but but 

i=3 
j=1 is possible 
no 

[10,20,30]

j is always in the right side of i.


Change -:
for(int j=i+1;j<n-1;j++)



Case4-: 
In recursion -> return helper(1,n-1)
In tabulation -> return dp[1,n-1].

Note-: Rest all are same.


Time  ->O(N^3)
Space ->O(N^2)

Code-:
int matrixMultiplication(vector<int> &arr) {
        int n=arr.size();
        // int memo[101][101];
        // memset(memo,-1,sizeof(memo));
        // return helper(memo,arr,1,n-1);
        int dp[n][n];
        for(int i=0;i<n;i++)
        {
          dp[i][i]=0;
        }
       
        for(int i=n-1;i>=1;i--)
        {
            for(int j=i+1;j<=n-1;j++)
            {
                int ans=INT_MAX;
                for(int k=i;k<=j-1;k++)
                {
                    int steps=arr[i-1]*arr[k]*arr[j] + dp[i][k] + dp[k+1][j];
                    ans=min(ans,steps);
                }
                dp[i][j]=ans;
            }
        }
        return dp[1][n-1];
}




Java :

Solution 1:

Code:
public class Solution {
    public static int helper(int[] arr, int i, int j) {
        if (i == j) return 0;
        int ans = Integer.MAX_VALUE;
        
        for (int k = i; k <= j - 1; k++) {
            int val = arr[i - 1] * arr[k] * arr[j]
                    + helper(arr, i, k)
                    + helper(arr, k + 1, j);
            ans = Math.min(ans, val);
        }
        return ans;
    }

    public static int matrixMultiplication(int[] arr) {
        int n = arr.length;
        return helper(arr, 1, n - 1);
    }
}




Solution 2:

public class Solution {
    public static int helper(int[][] memo, int[] arr, int i, int j) {
        if (i == j) return 0;
        if (memo[i][j] != -1) return memo[i][j];

        int ans = Integer.MAX_VALUE;
        for (int k = i; k <= j - 1; k++) {
            int val = arr[i - 1] * arr[k] * arr[j]
                    + helper(memo, arr, i, k)
                    + helper(memo, arr, k + 1, j);
            ans = Math.min(ans, val);
        }

        return memo[i][j] = ans;
    }

    public static int matrixMultiplication(int[] arr) {
        int n = arr.length;
        int[][] memo = new int[101][101];

        // Initialize all values to -1
        for (int i = 0; i < 101; i++) {
            for (int j = 0; j < 101; j++) {
                memo[i][j] = -1;
            }
        }

        return helper(memo, arr, 1, n - 1);
    }
}
