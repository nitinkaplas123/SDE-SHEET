Solution 1-:
Steps-:
1)When k is equal to N [7,2,5,10,8]
  if(k==n)
  then every element is in separate group.
  
  [7],[2],[5],[10],[8]  => its the sum of respective subarray.
  answer is 10.
Min -> max value of the array.

2)When k is 1.[7,2,5,10,8]
  add all the elements in a single group.
  [7+2+5+10+8]
  [32]  
  answer is 32.
  
  Max -> sum of all the values of the array.

Note-: our answer will lies in the range of min and max.

Note-: make sure in constraint k<=n.

if(k>n) return -1 because we cannot make k subarrays here. 

Time->O(Nlog(sum-maxValue)
Space->O(1)
Code-:
bool helper(vector<int>&nums,int k,int target)
{
        int val=nums[0];
        int count=1;
        for(int i=1;i<nums.size();i++)
        {
            val+=nums[i];
            if(val>target)
            {
                count++;
                val=nums[i];
            }
        }
        return (count<=k);
}
int splitArray(vector<int>& nums, int k) {
        int n=nums.size();
        int maxxVal=nums[0];
        int sum=nums[0];

        for(int i=1;i<n;i++)
        {
            maxxVal=max(maxxVal,nums[i]);
            sum+=nums[i];
        }

        int low=maxxVal;
        int high=sum;
        int ans=-1;
        while(low<=high)
        {
            int mid=(low+high)/2;
            if(helper(nums,k,mid))
            {
                ans=mid;
                high=mid-1;
            }
            else
            low=mid+1;
        }
        return ans;
}