
Solution :
Steps:
1)min value -> minValue from an array.
2)max value ->maxValue from an array.

bloomDays -> 0th flower will bloom/grow on 7thday , 4th flower will bloom/grow on 12 days.
1)Min value is 7  -> means on 7th days all the flower blooms those val is 7. (which is min value from an array).
2)Max value is 12 -> means on 12th days as its max value which make all the flowers of an array will blooms.
Input: bloomDay = [7,7,7,7,12,7,7], m = 2, k = 3    


range is {7,12}

1)low=7.
  high=12
  mid=9

 here bouq=1(we make).
 low=mid+1.
 low=10.

2)low=10;
  high=12.
  mid=11

  here bouq=1.(we make).

  low=mid+1.

3)low=12
  high=12.
  mid=12.

  here bouq=2(we make).

  it return true.

  ans=12
  high=mid-1
  high=11.

  break the while loop.

Output -: 12


Time->O(Nlog(maxValue-minValue))
Space->O(1)
Code:
bool helper(vector<int>&nums,int m,int k,int days)
{
        int count=0;
        int bouq=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]<=days)
            {
               count++;
               if(count==k)
               {
                   bouq++;
                   count=0;
               }
            }
            else
            count=0;
        }
        return (bouq>=m);
}
int minDays(vector<int>&nums, int m, int k) {
        int n=nums.size();
        if((long long)m*k>n) return -1;
        int mini=nums[0];
        int maxi=nums[0];
        for(int i=1;i<nums.size();i++)
        {
            mini=min(mini,nums[i]);
            maxi=max(maxi,nums[i]);
        }

        int low=mini;
        int high=maxi;
        int ans=-1;
        while(low<=high)
        {
            int mid=(low+high)/2;
            if(helper(nums,m,k,mid))
            {
                ans=mid;
                high=mid-1;
            }
            else
            low=mid+1;
        }
        return ans;
}