Solution 1-:
Steps:
1)Starting with k=1 and increase one by one.
  when we see hours_used>hours_given
  return k.


Solution 2-:
Steps-:
1)min value -> k=1.
2)max value -> k=max_value of an array.

[3,6,7,11]

here -:
Min value : k=1  which makes hours -> 3+6+7+11.
Max value : k=11 which makes hours -> 1+1+1+1  

why k->maxValue 
you can take k=20 
                                      [3,6,7,11]
thats also take same no. of hours ->   1+1+1+1 => 4.



Time->O(Nlog(maxxValue))
Space->O(1)
Code-:
bool isValid(vector<int>&piles,int h,int hours)
{
        long long int count=0;
        for(int i=0;i<piles.size();i++)
        {
            if(piles[i]%hours==0)
            count+=(piles[i]/hours);
            else
            count+=(piles[i]/hours)+1;
        }
        return (count<=h);
}
int minEatingSpeed(vector<int>& piles, int h) {
        int n=piles.size();
        int maxxValue=*max_element(piles.begin(),piles.end());
        int low=1;
        int high=maxxValue;
        int ans=-1;
        while(low<=high)
        {
            int mid=(low+high)/2;
            if(isValid(piles,h,mid))
            {
                ans=mid;
                high=mid-1;
            }
            else
            low=mid+1;
        }
        return ans;
}