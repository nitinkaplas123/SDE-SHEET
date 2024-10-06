Question -:
1)Here we are given two arrays where nums1 is subset of num2.
  means all the elements of num1 will be in nums2.
2)We have to find the next greater element of nums1 element in nums2.


Steps-:
1)first we store all the next greater value of nums2 in vector using stack.
2)Now we are storing the nums2[i] and its next greater element in map.
3)Now we are traversing the nums1 and find the next greater element in map.

Code-: Time->O(N)  Space->O(N)
vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n=nums2.size();
        vector<int>v;
        stack<int>st;
        st.push(n-1);
        v.push_back(-1);
        for(int i=n-2;i>=0;i--)
        {
            while(st.empty()==false and nums2[st.top()]<=nums2[i])
            {
                st.pop();
            }
            if(st.empty())
            v.push_back(-1);
            else
            v.push_back(nums2[st.top()]);
            st.push(i);
        }

        reverse(v.begin(),v.end());

        unordered_map<int,int>m;
        for(int i=0;i<n;i++)
        {
            m[nums2[i]]=v[i];
        }

        int n1=nums1.size();
        vector<int>ans;
        for(int i=0;i<n1;i++)
        {
             ans.push_back(m[nums1[i]]);
        }
        return ans;
}