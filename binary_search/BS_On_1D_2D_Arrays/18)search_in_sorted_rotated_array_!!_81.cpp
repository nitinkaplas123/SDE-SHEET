Solution 1-:
Steps-:
1)Same idea as we do in search_in_rotated_sorted_1 
2)just a bit of change because in that question no duplicate allowed.
3)here there is duplicated.

test case where thats failed.

 0 1 2 3 4 5 6
[3,1,2,3,3,3,3]     target=1

low=0 high=6 
mid=3

here firstly we check 
if(nums[mid]==target)
return true;

but here 3!=1

due to duplicate we see both left and right is sorted but its not true.

 0 1 2 3 4 5 6
[3,1,2,3,3,3,3]
low=0 mid=3 high=6 
where left half is not sorted and 
we know that mid is not our target which means low and high is also not target
so we shrinked the array. 
low++ high--;  in this case.


Rest all are same.


Code-: Time->O(logn)
bool search(vector<int>& nums, int target) {
        int n=nums.size();

        int low=0;
        int high=n-1;
        while(low<=high)
        {
            int mid=(low+high)/2;

            if(nums[mid]==target)
            return true;
            else if(nums[mid]==nums[low] and nums[mid]==nums[high])
            {
                low++;
                high--;
            }
            else if(nums[low]<=nums[mid])
            {
                if(target>=nums[low] and target<=nums[mid])
                high=mid;
                else
                low=mid+1;
            }
            else
            {
                if(target>=nums[mid+1] and target<=nums[high])
                low=mid+1;
                else
                high=mid;
            }
        }
        return false;
    }

