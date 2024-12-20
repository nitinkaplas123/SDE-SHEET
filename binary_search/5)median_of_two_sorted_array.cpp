Solution 1-:
Steps-:
1)Make a vector v where we put both the vector into it in sorted order.
2)Two cases-:
  1. If the n1+n2 %2==0 means even
     return (v[(n1+n2)/2] + v[(n1+n2)/2-1])/2;
  2. If its odd
     return (v[(n1+n2)/2])


Code-:
double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1=nums1.size();
        int n2=nums2.size();

        vector<int>v;
        int i=0;
        int j=0;
        while(i<n1 and j<n2)
        {
            if(nums1[i]<nums2[j])
            {
                v.push_back(nums1[i]);
                i++;
            }
            else
            {
                v.push_back(nums2[j]);
                j++;
            }
        }

        while(i<n1)
        {
            v.push_back(nums1[i++]);
        }

        while(j<n2)
        {
            v.push_back(nums2[j++]);
        }
      
        double ans;
        if((n1+n2)%2==0)
        ans=(v[(n1+n2)/2] +v[(n1+n2)/2-1])/2.0;
        else
        ans=(v[(n1+n2)/2]);

        return ans; 
}


Solution 2-:
Steps-:
1)Here we have n1 and n2 as size of vector.
2)In this approach n1<=n2 alaways if n1>n2 then swap the num1 and num2
3)Now here low=0 and high=n1 to find the mid point we use this // dry run 
  num1=[2]
  num2=[1,3]
4)Here we find i1 as mid point in num1 (low+high)/2
  here we find i2 as mid point in num2 (n1+n2+1)/2-i1
5)we find the min1, min2 as right side
  we find the max1,max2 as left side of array

  simply means we divide both the array into left and right side where left side values  will be smaller than
  right side of the array

  Three cases-:
  1)if max1<=min2 and max2<=min1
    then find the median.
  2) if max2>min1
     which means we have to go right side 
     so low=i1+1 
  3) if max1>min2
     which means we have to go left side
     so high=i1-1

Run this test case why high=n1 not  n1-1;
Input: nums1 = [1,2], nums2 = [3,4]
Output: 2.50000

Code-:
double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1=nums1.size();
        int n2=nums2.size();

        if(n1>n2)
        return findMedianSortedArrays(nums2,nums1);

        int low=0;
        int high=n1;

        while(low<=high)
        {
            int i1=(low+high)/2;
            int i2=(n1+n2+1)/2-i1;

            int max1=(i1==0)?INT_MIN:nums1[i1-1];
            int max2=(i2==0)?INT_MIN:nums2[i2-1];
            int min1=(i1==n1)?INT_MAX:nums1[i1];
            int min2=(i2==n2)?INT_MAX:nums2[i2];
            
            double res;
            if(max1<=min2 and max2<=min1)
            {
                if((n1+n2)%2==0)
                res=(max(max1,max2) + min(min1,min2))/2.0;
                else
                res=max(max1,max2);
                return res;
            }
            else if(max2>min1)
            low=i1+1;
            else
            high=i1-1; 
        }
        return 1.0;
    }
