Solution 1:

Steps:
1. Find the maximum value in arr1.
2. Count the frequency of each element in arr1 using a counting sort approach.
3. Add elements to the result in the order specified by arr2, based on frequency.
4. Append the remaining elements in ascending order.


Time -> O(N+M)
Space ->O(Maxi+1)

Code:

vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        vector<int>ans;
        int n1=arr1.size();
        int n2=arr2.size();

        int maxi=*max_element(arr1.begin(),arr1.end());
        
        vector<int>count(maxi+1,0);
        for(int i=0;i<n1;i++)
        {
            count[arr1[i]]++;
        }

        for(int i=0;i<n2;i++)
        {
            int val=arr2[i];
            int freq=count[val];
            while(freq--)
            {
                ans.push_back(val);
            }
            count[val]=0;
        }

        for(int i=0;i<=maxi;i++)
        {
            if(count[i]!=0)
            {
                int freq=count[i];
                while(freq--)
                {
                    ans.push_back(i);
                }
            }
        }
        return ans;
}