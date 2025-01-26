Solution 1-:
Steps-:
1)First fill the temp array. 
2)Now find the max len in the temp array and its corresponding index. 
3)Now from that index we have to store our lis. 
4)Here we need one more array suppose -> hash where we store the index. 
5)hash array will be change its index when we are changing the temp array.

Step1-:
arr=>   [5,4,11,1,16,8]
        0  1 2 3 4 5
temp=>  [1,1,2,1,3,2]

hash  -> [0,1,0,3,2,0]


maxx -> 3 
index-> 4 


Dry run -:

arr=>   [5,4,11,1,16,8]

        0  1 2 3 4 5
temp=>  [1,1,1,1,1,1]

hash  -> [0,1,2,3,4,5]



1) i=1 
   nothing change 
           1 
arr=>   [5,4,11,1,16,8]

        0  1 2 3 4 5
temp=>  [1,1,1,1,1,1]

hash  -> [0,1,2,3,4,5]



2) i=2  
             1
arr=>   [5,4,11,1,16,8]

        0  1 2 3 4 5
temp=>  [1,1,1,1,1,1]

hash  -> [0,1,2,3,4,5]

i=2, 
j=0 

here i update temp[i]=1+temp[j]
same time hash[i]=j;

        0  1 2 3 4 5
temp=>  [1,1,2,1,1,1]

hash  -> [0,1,0,3,4,5]


Means whenever we are chahing in temp[i] -> we change the path in hash[i]=j;


Step2=:
1)Same time -> updated maxx value and its corresponse index;


Steps3-:
1)Now hash is look like this 
  Index=4 

arr=>   [5,4,11,1,16,8]
        0  1 2 3 4 5
temp=>  [1,1,2,1,3,2]

          0 1 2 3 4 5
hash  -> [0,1,0,3,2,0]



1) hash[4]!=4
ans->  [16]
index=2 


2) hash[2]!=2
ans -> [16,11]
index=0

3)hash[0]!=0 break; 


ans -> [16,11,5]

reverse -> [5,11,16]

O/P -> [5,11,16]





Code-:
vector<int> longestIncreasingSubsequence(int n, vector<int>&nums) {
        vector<int>temp(n,1);
        vector<int>hash(n);
        for(int i=0;i<n;i++)
        {
            hash[i]=i;
        }
        
        int maxx=1;
        int index=0;
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(nums[i]>nums[j])
                {
                    if(temp[i]<temp[j]+1)
                    {
                        temp[i]=1+temp[j];
                        hash[i]=j;
                    }
                }
            }
            if(maxx<temp[i])
            {
                maxx=temp[i];
                index=i;
            }
        }
        
        vector<int>ans;
        
        while(hash[index]!=index)
        {
            ans.push_back(nums[index]);
            index=hash[index];
        }
        ans.push_back(nums[index]);
        
        reverse(ans.begin(),ans.end());
        return ans;
}