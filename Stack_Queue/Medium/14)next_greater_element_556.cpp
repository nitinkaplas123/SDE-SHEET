Solution 1-:
Steps-;
1)using same as next_permutation approach.

Case1-:
[2,1] -> [1,2] 

but here we need greater if not possible return -1.
if(ori>=ans) return -1;


Case2-: 
[INT_MAX] -> next greater of it 
so ans>INT_MAX 
but question said u will be within the limit 
return -1.

Code-:
int nextGreaterElement(int n) {
        string str=to_string(n);
        int len=str.length();

        int index=0;
        for(int i=len-2;i>=0;i--)
        {
            if(str[i]<str[i+1])
            {
                index=i;
                break;
            }
        }
       

        for(int i=len-1;i>=0;i--)
        {
            if(str[i]>str[index])
            {
                swap(str[i],str[index]);
                index++;
                break;
            }
        }

        int low=index;
        int high=len-1;
        while(low<high)
        {
            swap(str[low],str[high]);
            low++;
            high--;
        }

        long long int ans=stoll(str);
        long long int ori=(long long)n;
        if(ans<=ori) return -1;
        if(ans>INT_MAX) return -1;
        return (int)ans;
}



class Solution:
    # Function to find max water container
    def maxArea(self, height):
        n = len(height)
        max_water = 0
        left, right = 0, n - 1  # Two pointers

        # Iterate while the two pointers haven't met
        while left < right:
            width = right - left  # Width between lines
            min_height = min(height[left], height[right])  # Height of container
            max_water = max(max_water, width * min_height)  # Update max area if current is larger

            # Move the pointer at the smaller height
            if height[left] < height[right]:
                left += 1
            else:
                right -= 1

        return max_water