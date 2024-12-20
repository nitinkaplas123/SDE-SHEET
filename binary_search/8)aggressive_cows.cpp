Notebook 1 Page 30

Refernce ->https://www.youtube.com/watch?v=R_Mfw4ew-Vo

Solution 1-:
Steps-:
1)We sort the given array because we need min distance so minimum distance is bw its consecutive pairs.
2)Now we have to make k cows to n stalls for that we always make 1st cow at 0 index which make count=1;
  and to calculate the distance bw them we use prev and curr varible.
3) Idea to calculate (min distance bw 2 cows) should be max is-:
   in starting we assume ans=1,
   now we have to put k cows in such a way that difference bw 2 cows >=1 where 1 is ans.
   every time when we put cow at some position then count++
   Two cases-:
   1)when count==k which means we put k cows succesfully and its differnce is greater than or equal to ans .
   2)when count<k means we cannot put k cows but reach to end of the array which means we cannot put cows 
     with difference >=ans here we have to break the upper while loop.


Dry run-:
n=5 
k=3
stalls = [10 1 2 7 5]

1)Sort the array  [1,2,5,7,10]
2)Now we assume ans=1 
  
  1. [1,2,5,7,10]                                1    2    5   7   10
     prev=0, curr=1                              c1   c2    c3               (2-1),(5-2)
     ans=1                                                                   min(1    , 3)  => 1 

  
  2. [1,2,5,7,10]                                1    2     5    7   10
      prev=0,curr=1
      ans=2                                      c1         c2   c3          min(5-1,7-5)   => 2


  3. [1,2,5,7,10]
      prev=0,curr=1                              1     2    5    7    10
      ans=3                                      c1         c2        c3      min(5-1,10-5)   =>4 


  4. [1,2,5,7,10]
      prev=0,curr=1                              1     2    5    7    10
      ans=4                                      c1         c2        c3       min(5-1,10-5)  => 4


  
   
  5. [1,2,5,7,10]
      prev=0,curr=1                              1     2    5    7    10
      ans=5                                      c1              c2           here we cannot put c3 cow means.
                                                                              count<k but curr==n  here we 
                                                                              break the loop.

    So our answer is ans-1      =>4 


Code-: Time->O(N*10^9)
int solve(int n, int k, vector<int> &stalls) {
       sort(stalls.begin(),stalls.end());    n log(10^5)
       int ans=1;
       while(1)          O(10^9)
       {
           int count=1;
           int prev=0;
           int curr=1;
           while(curr<n and count<k)  O(N)
           {
               if(stalls[curr]-stalls[prev]>=ans)
               {
                   count++;
                   prev=curr;
                   curr++;
               }
               else
               curr++;
           }
           if(count==k)
           ans++;
           else
           break;
       }
       return ans-1;
    }

                                                            


Solution 2-:
Steps-:
1)Same approach just change is where we check eligible ans=1 to n 
  here we use 
  low=1 and max is difference of last-first

  eg. 
  [1,2,5,7,10]
  low=1 
  high=(10-1) =>9  because min cows will be 2 so (10-1)=>will be possible maximum answer.

2)low=1 
  high=9
3)while(low<=high)
4)int mid=(low+high)/2;
   
1. 
   low=1 high=9
   mid=(1+9)/2=>5

   so we check is 5 is possible in our array.

   [1,2,5,7,10]  k=3
    
    1   2   5   7   10
    c1          c2       =>not possible

    here count<k   which means we have to go left_side.

    high=mid-1;
  
2.
    low=1 
    high=4
    mid=(1+4)/2  => 2

    1   2   5   7   10
    c1      c2   c3 

    here count>=k  means ans may be 3 but we means max of min.
    ans=mid; 
    low=mid+1;        ans=3

3. low=4
   high=4
   mid=4

   1   2   5   7   10
   c1      c2      c3 

   here count>=k  means ans may be 3 but we means max of min.
    ans=mid; 
    low=mid+1;        ans=4


4.  low=5
    high=4

    here we break the loop.


o/p ->4


Code-:  Time->O(n*log(10^9))
int solve(int n, int k, vector<int> &stalls) {
       sort(stalls.begin(),stalls.end());
       int mid;
       int low=1;
       int high=stalls[n-1]-stalls[0];
       int res;
       while(low<=high)          o(log(10^9))
       {
           int mid=(low+high)/2;
           int count=1;
           int prev=0;
           int curr=1;
           while(curr<n and count<k)       o(n)
           {
               if(stalls[curr]-stalls[prev]>=mid)
               {
                   count++;
                   prev=curr;
                   curr++;
               }
               else
               curr++;
           }
           if(count<k)
           high=mid-1;
           else
           {
               res=mid;
               low=mid+1;
           }
       }
       return res;
}







