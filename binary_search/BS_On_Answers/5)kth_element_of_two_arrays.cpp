Median of two sorted array.
Code-:
int kthElement(vector<int>&nums1, vector<int>&nums2, int k) {
        int n1=nums1.size();
        int n2=nums2.size();
       
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
            {
               int n=n1+n2;
               if(n%2==0)
               return ((double)max(max1,max2) + (double)min(min1,min2))/2.0;
               else
               return (double)max(max1,max2);
            }
            else if(min1<max2)
            low=i1+1;
            else
            high=i1-1;
        }
        return 0.0;
}


Note: Here we split the arrays into two equal half 
      if (n1+n2 is even)

      if(n1+n2 is odd)
      extra element in left side.

    

Question: kth elements of two sorted array.

here we split in two half 

left side         right side.
k elements       (n1+n2-k) elements 
     

Note: return max(max1,max2) because our kth element is in left side. because in left side we have k element.


Change1: 
Before Change:

int i1=(low+high)/2;
int i2=(n1+n2+1)/2-i1;


After change:
int i1=(low+high)/2;
int i2=(k-i1).


Change2:
Before Change:
if(max1<=min2 and max2<=min1)
{
        int n=n1+n2;
        if(n%2==0)
        return ((double)max(max1,max2) + (double)min(min1,min2))/2.0;
        else
        return (double)max(max1,max2);
}

After Change:
if(max1<=min2 and max2<=min1)
{
    return max(max1,max2);
}


Change3:
Before Change:
low=0;
high=n1

Input: a[] = [2, 3, 6, 7, 9], b[] = [1, 4, 8, 10], k = 1

low=0  high=5 
we want 1 element then why our range is 0 to 5. 
means we have to reduce the range right ?


After Change:
//##### high=min(n1,k)  
high=1.

range [0,1]



Change4:
Before Change:

Input: a[] = [2, 3, 6, 7, 9], b[] = [1, 4, 8, 10], k = 8

means 
left side -> k elements -> 8        
right side -> 1.

low=0      high=min(5,8)
low=0      high=5.

here range is [0,5]  means either we take 0 elements or 1 elememnts or 2 or 3 or 4 or 5.
think can we take 0 elements from nums1 arrays ?
no 
why 

we want 8 elements if i take all the elements from array b to the left side which count is 4 
still i need 4 more element which we take from array a.

so thats why our 
//#### low=max(0,k-n2)
low=max(0,4)
low=4.



Code-:
int kthElement(vector<int>&nums1, vector<int>&nums2, int k) {
        int n1=nums1.size();
        int n2=nums2.size();
       
        int low=max(0,k-n2);   // change1 
        int high=min(n1,k);    //change 2 
        while(low<=high)
        {
            int i1=(low+high)/2;
            int i2=k-i1;        //change 3
            int max1=(i1==0)?INT_MIN:nums1[i1-1];
            int max2=(i2==0)?INT_MIN:nums2[i2-1];
            int min1=(i1==n1)?INT_MAX:nums1[i1];
            int min2=(i2==n2)?INT_MAX:nums2[i2];

            if(max1<=min2 and max2<=min1)
            return max(max1,max2);   //change 4.
            else if(min1<max2)
            low=i1+1;
            else
            high=i1-1;
        }
        return 0.0;
}