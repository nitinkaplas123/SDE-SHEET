Solution 1-:
Steps-:
1)Min divisor value is 1.
for eg.
nums = [1,2,5,9], threshold = 6

1/1=1
2/1=2
5/1=5
9/1=9 

sum -> 1+2+5+9 -> 17

2)Max divisor is -> maxValue from an array. 
for eg.
nums = [1,2,5,9], threshold = 6

1/9=1
2/9=1
5/9=1
9/9=1

sum -> 1+1+1+1 -> 4

Range is 1 to 9.

Note-: You have to find the smallest divisor those sum<=threshold.

3)Rest all is same as we did in previous questions.


Time->O(Nlog(maxValue))
Space->O(1)
Code-:
bool helper(vector<int>&nums,int threshold,int divisor)
{
        int count=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]%divisor==0)
            count+=(nums[i]/divisor);
            else
            count+=(nums[i]/divisor)+1;
        }
        return (count<=threshold);
}
int smallestDivisor(vector<int>& nums, int threshold) {
        int n=nums.size();
        int maxValue=0;
        for(int i=0;i<n;i++){
           maxValue=max(maxValue,nums[i]);
        }

        int low=1;
        int high=maxValue;
        int ans=-1;
        while(low<=high)
        {
            int mid=(low+high)/2;
            if(helper(nums,threshold,mid))
            {
                ans=mid;
                high=mid-1;
            }
            else
            low=mid+1;
        }
        return ans;
}