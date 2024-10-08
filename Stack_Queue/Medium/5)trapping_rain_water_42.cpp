Leetcode-42

Solution 1-: Time->O(n2)  Space->O(1)
Steps-:
1)Have to find the left_max and right_max for the current element.
2)Then min(left_max,right_max)- current element is the water we can store in current height.

Code-:
int trap(vector<int>& height) {
        int n=height.size();
        int ans=0;

        for(int i=1;i<n-1;i++)
        {
           int left_max=height[i];
           for(int j=i-1;j>=0;j--)
           {
               left_max=max(left_max,height[j]);
           }

           int right_max=height[i];
           for(int j=i+1;j<n;j++)
           {
               right_max=max(right_max,height[j]);
           }

           ans+=min(left_max,right_max)-height[i];
        }
        return ans;
    }


Solution 2-:
Steps-:
1)Make an array left_max 
2)Make an array right_max
3)Now using these both array find the min value from both and minus with current height.


Code-: Time ->O(n)  Space ->O(N)

int trap(vector<int>& height) {
       int n=height.size();

       int left_max[n];
       left_max[0]=height[0];

       for(int i=1;i<n;i++)
       {
           left_max[i]=max(left_max[i-1],height[i]);
       }

       int right_max[n];
       right_max[n-1]=height[n-1];
       for(int j=n-2;j>=0;j--)
       {
           right_max[j]=max(right_max[j+1],height[j]);
       }

       int ans=0;
       for(int i=1;i<n-1;i++)
       {
           ans+=min(left_max[i],right_max[i])-height[i];
       }
       return ans;
    }



Solution 3-:  Time->O(N) Space ->O(1)

Steps-:
1)Using same intuition we use here 
2)Instead of making array storing we can replace with variable here 


Code-:
int trap(vector<int>& height) {
       int n=height.size();
       
       int ans=0;
       int lmax=height[0];
       int rmax=height[n-1];

       int low=1;
       int high=n-2;
       while(low<=high)
       {
           lmax=max(lmax,height[low]);
           rmax=max(rmax,height[high]);
           if(rmax>lmax)
           ans+=lmax-height[low++];
           else
           ans+=rmax-height[high--];
       }
       return ans;
    }
