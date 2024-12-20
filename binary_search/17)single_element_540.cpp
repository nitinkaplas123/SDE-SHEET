Solution 1-:
Steps-:
1)Using hashmap


Solution 2-:
Steps-:
1)Using xor opeartion 


Solution 3-:
Steps-:
[1,1,2,2,3,4,4,5,5]

1)If we observed 3 is the single element.
2)Two cases-:
  1. left side of single element
      0 1 2 3 4
     [1,1,2,2,3]

     (even,odd)


  2. right side of single element
      4 5 6 7 8  
     [3,4,4,5,5]

     (odd,even)  4 (o,e)   5 (o,e)

3) if arr[mid]!=arr[mid-1] and arr[mid]!=arr[mid+1]
   means mid is the single element

   for 0 and n-1 index we have to check separately.



Dry run 

 0 1 2 3 4 5 6 7 8
[1,1,2,3,3,4,4,8,8]

1)low=1; high=7
  mid=4

  here nums[mid]==arr[mid-1]
  if(mid%2==0)  (odd,even) then go to left side
  high=mid-1
  else
  low=mid+1

    0 1 2 3 4 5 6 7 8 9 10
2) [1,1,2,3,3,4,4,8,8,9,9]

   low=1 high=9
   mid=5 

   here nums[mid]==nums[mid+1]
   here (mid%2!=0) means mid is odd 
   means (odd,even)

   means single element is at left side.
   if(mid%2!=0)
   high=mid-1;
   else
   low=mid+1;


Code-: Time->O(Logn)
int singleNonDuplicate(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return nums[0];
        if(nums[0]!=nums[1]) return nums[0];
        if(nums[n-1]!=nums[n-2]) return nums[n-1];

        int low=1;
        int high=n-2;
        while(low<=high)
        {
            int mid=(low+high)/2;
            if(nums[mid]!=nums[mid-1] and nums[mid]!=nums[mid+1])
            return nums[mid];
            else if(nums[mid]==nums[mid-1])
            {
                if(mid%2==0)
                high=mid-1;
                else
                low=mid+1;
            }
            else
            {
               if(mid%2!=0)
               high=mid-1;
               else
               low=mid+1;
            }
        }
        return -1;
    }













