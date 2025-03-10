https://www.geeksforgeeks.org/problems/sum-of-middle-elements-of-two-sorted-arrays2305/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=practice_card

Solution 1-:
Steps-:
1)Using same as standard question of median of two sorted array.
2)Either n1+n2 is odd or even 
  answer -> max from left side + min(right side).

Time->O(log(n))
Code-:
int SumofMiddleElements(vector<int> &nums1, vector<int> &nums2) {
        int n1=nums1.size();
        int n2=nums2.size();
        if(n1>n2) return SumofMiddleElements(nums2,nums1);
        
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

            if(max1<=min2 and max2<=min1)
            return (max(max1,max2) + min(min1,min2));
            else if(min1<max2)
            low=i1+1;
            else
            high=i1-1;
        }
        return 0;
}