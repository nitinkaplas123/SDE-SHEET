Dry run -:
[5,1,2,3,4]

SOlution 1-:
Steps-:
1)low=0 high=n-1;
[3,4,5,1,2]



2)Two cases-:
  1. if left half is sorted 
     arr[low]<=arr[mid]
     means min element in left side is arr[low]
     ans=min(ans,arr[low])
     low=mid+1;
     beacause we have min element in left side so now go to right side.


  2. if right side is sorted 
     [3,1,2]

     low=0 high=2
     mid=1 

     arr[mid]>=arr[low]  left side is not sorted.
     means right side is sorted.

     if right side is sorted then min element from right side is arr[mid+1] 
     ans=min(ans,arr[mid+1])
     high=mid.
     beacause we have min elemenet from right side. 
     but mid is not evaluated yet so 
     high=mid.


Code-: Time->O(logN)
int findMin(vector<int>& nums) {
        int n=nums.size();
        int low=0;
        int high=n-1;
        int ans=INT_MAX;
        while(low<=high)
        {
            int mid=(low+high)/2;
           
            if(nums[mid]>=nums[low])
            {
                ans=min(ans,nums[low]);
                low=mid+1;
            }
            else
            {
               ans=min(ans,nums[mid+1]);
               high=mid;
            }
        }
        return ans;
    }

