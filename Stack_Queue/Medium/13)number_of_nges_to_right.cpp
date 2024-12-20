https://www.geeksforgeeks.org/problems/number-of-nges-to-the-right/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=number-of-nges-to-the-right

Question -:
1)Here we are given indexies where we have to count the no. of greater elements to the 
  right side of given index value.

Intution -: Brute forced.

Steps-:
1)simply we just traverse the queries and then 
  val=arr[index];
2)now traverse array from index to n-1 if curr_element>val 
  count++;

Code-:
vector<int> count_NGE(int n, vector<int> &arr, int queries, vector<int> &indices){
        vector<int>ans;
        for(int i=0;i<queries;i++)
        {
            int index=indices[i];
            int count=0;
            int val=arr[index];
            for(int i=index+1;i<n;i++)
            {
                if(arr[i]>val)
                count++;
            }
            ans.push_back(count);
        }
        return ans;
}