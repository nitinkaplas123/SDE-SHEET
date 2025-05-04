Solution 1:

Steps:
1)using 2 nested loop.

Time Complexity: O(N^2)
Space Complexity: O(1)

Code:
long long countSubarrays(vector<int>& nums, long long k) {
        long long ans=0;
        int n=nums.size();

        for(int i=0;i<n;i++)
        {
            long long sum=0;
            long long score=0;
            for(int j=i;j<n;j++)
            {
               sum+=nums[j];
               score=(sum*(j-i+1));
               if(score<k)
               ans++;
            }
        }
        return ans;
}



Solution 2:
Steps:
1)We are using sliding window where we have i and j pointers.
  
Intution :
 i     j   
[a,b,b,x,x,t,y,u,i,o]


Just imagine if from window i to j the score is less than k 

[a,b,b,x] is the correct subarray which score<k 
can we say that 
[b,b,x] subarray also has score<k
[b,x]
[x]  yes we can say that 


Dry run:
nums = [2,1,4,3,5], k = 10

    i
    0 1 2 3 4
1) [2,1,4,3,5]
    j

sum=2 
score=2 

ans+=(j-i+1) 
ans=1       [2]
j++

    i
    0 1 2 3 4
2) [2,1,4,3,5]
      j
sum=3
score=6

score<k 
ans=1+2=3    [2,1],[1]

j++ 

    i
    0 1 2 3 4
3) [2,1,4,3,5]
        j

sum=7 
score=21

      i
    0 1 2 3 4
3) [2,1,4,3,5]
        j

score>=k
sum=5
score=10
i++

again 

        i
    0 1 2 3 4
3) [2,1,4,3,5]
        j

score>=k
sum=4 
score=4

ans=3+1 [4]
j++

        i
    0 1 2 3 4
4) [2,1,4,3,5]
          j


sum=7
score=14

sum=3
score=3

          i
    0 1 2 3 4
   [2,1,4,3,5]
          j

ans=4+1     [3]

j++

5)        i
    0 1 2 3 4
   [2,1,4,3,5]
            j

sum=8 
score=16 
i++
            i
    0 1 2 3 4
   [2,1,4,3,5]
            j

sum=5
score=5
ans=5+1   [5]



o/p :6 




Time Complexity: O(N)
Space Complexity: O(1)

Code:
long long countSubarrays(vector<int>& nums, long long k) {
        int n=nums.size();
        long long ans=0;

        int i=0;
        int j=0;
        long long sum=0;
        long long score=0;

        while(j<n)
        {
            sum+=nums[j];
            score=(sum*(j-i+1));

            while(score>=k)
            {
                sum-=nums[i];
                i++;
                score=(sum*(j-i+1));
            }
            ans+=(j-i+1);
            j++;
        }
        return ans;
}