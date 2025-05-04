Solution 1 -:
1)using inbuilt function 

Code-:
int mySqrt(int x) 
{
       return sqrt(x);
}

Solution 2-:
1)Using pow function 

Code-:
int mySqrt(int x)
{
      return pow(x,.5);
}

Solution 3-: Time->O(Log(N))
Steps-: 
1)Make a number line low=0 high=x
2)Find the mid of it.
3)If mid*mid==x then return the mid;
4)Else if mid*mid>x here our ans is on left side so high=mid-1
5)mid*mid<x here our ans may be mid so we store (ans=mid) because we need floor of it and go to right side
  low=mid+1


Code-:
int mySqrt(int x) 
{
      int low=0;
      int high=x;
      int ans=-1;
      while(low<=high)
      {
          long long int mid=(low+high)/2;
          if(mid*mid==x)
          return mid;
          else if(mid*mid>x)
          high=mid-1;
          else
          {
              ans=mid;
              low=mid+1;
          }
      }
      return ans;
}