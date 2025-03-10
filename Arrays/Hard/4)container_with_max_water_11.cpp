Solution 1-:
Steps-:
1)using 2 for loops.
2)Make all possible container.

Code-:
int maxArea(vector<int>& height) {
        int n=height.size();
        int maxWater=0;
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                int wid=j-i;
                int minHeight=min(height[i],height[j]);
                int area=wid * minHeight;
                maxWater=max(maxWater,area);
            }
        }
        return maxWater;
}


Solution 2-:
Steps-:
1)are left=0 right=n-1.
2)now we find the width and min height out of both.
3)store the answer.
4)Now 2 pointer left is 0 right=n-1.
  u always deal with that.
  now if(left<right).
      left++;
      is any any sense to use left again no before left value is less and we already use it 
      with max width.
      so thats why left++;
      so that my height will increase.


Time=>O(N)
Space->O(1)
Code-:
int maxArea(vector<int>& height) {
        int n=height.size();
        int maxWater=0;
        int left=0;
        int right=n-1;

        while(left<right)
        {
            int minHeight=min(height[left],height[right]);
            int wid=right-left;
            int area=minHeight * wid;
            maxWater=max(maxWater,area);
            if(height[left]<height[right])
            left++;
            else
            right--;
        }
        return maxWater;
}