Solution 1-:
Steps:
Input: weights = [1,2,3,4,5,6,7,8,9,10], days = 5

1)MinValue: make all element as separate subarray (single element subarray) -> [1],[2],[3],[4],[5],[6]....[10] -> max from all subarray is 10.

2)MaxValue: make all the elements in a single subarray [1+2+3+4+.....+10] -> sum of all elements.

3)Range: [minValue,maxValue].

Code:
bool helper(vector<int>&nums,int days,int capacity)
{
        int currCap=nums[0];
        int currDays=1;

        for(int i=1;i<nums.size();i++)
        {
            currCap+=nums[i];
            if(currCap>capacity)
            {
                currDays++;
                currCap=nums[i];
            }
        }
        return (currDays<=days);
}
int shipWithinDays(vector<int>&nums, int days) {
        int n=nums.size();
        int maxValue=nums[0];
        int sum=nums[0];
        for(int i=1;i<n;i++){
            maxValue=max(maxValue,nums[i]);
            sum+=nums[i];
        }

        int low=maxValue;
        int high=sum;
        int ans=-1;
        while(low<=high)
        {
            int mid=(low+high)/2;
            if(helper(nums,days,mid))
            {
                ans=mid;
                high=mid-1;
            }
            else
            low=mid+1;
        }
        return ans;
}