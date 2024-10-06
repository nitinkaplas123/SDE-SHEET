Solution 1-:
Steps-:
1)in inner loop j we are running n-1 times so that we can compare all the elements with nums[i].



Code-: Time->O(N^2)
vector<int> nextGreaterElements(vector<int>& nums) {
        int n=nums.size();
        vector<int>ans;
        for(int i=0;i<n;i++)
        {
            int maxx=INT_MIN;
            int j;
            for(j=i+1;j<n+i;j++)
            {
                int index=(j%n);
                if(nums[index]>nums[i])
                {
                    ans.push_back(nums[index]);
                    break;
                }
            }
            if(j==n+i)
            ans.push_back(-1);
        }
        return ans;
}


Solution 2-:
Steps-:
1)Here first we calculate the last element ka next greater element.
  here we use the stack and put all the elements except last element in stack
  from n-2 to 0 element because last element ka next greater element is start from 
  0th index.

Case1-:
Top element of stack is element which is very close to current element.

if st.top()>nums[i] 
1. here we add the st.top elememt in my answer vector.
2. add the curr element in stack.
3. i--;

Case2-:
if the stack is empty 
1. no one is greater than this means this element is maxx element in array.
2. add the element in the stack.
3. i--

Case3-:
st.top() element is <nums[i]
1. pop the element.



Code-: Time->O(N) Space->O(N)
vector<int> nextGreaterElements(vector<int>& nums) 
{
        int n=nums.size();
        stack<int>st;
        for(int i=n-2;i>=0;i--)
        {
            st.push(nums[i]);
        }
        
        vector<int>ans;
        int i=n-1;
        while(i>=0)
        {
            if(st.empty()==false and st.top()>nums[i])
            {
                ans.push_back(st.top());
                st.push(nums[i]);
                i--;
            }
            else if(st.empty())
            {
                ans.push_back(-1);
                st.push(nums[i]);
                i--;
            }
            else
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
}