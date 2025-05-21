Solution 1:


[1,2,1,2]   k=2

find smallest subarray count=k

i_bada=0

 0 1 2 3
[1,2,1,2]
     i j 

index(2,3) is smallest substring with count equal to k.  -> [1,2]

then [2,1,2] is also valid 
then [1,2,1,2] is also valid 

count=(i-i_bada)+1 
count=3.


 0 1 2 3 4 
[1,2,1,2,3]


1)
i_bada=0;
i=0;
j=0;

m=[(1,1)]

2) j=1 

m=[(1,1),(2,1)]

this is perfect - smallest valid 

count=0+(i-i_bada+1)
     = 1


3) j=2

m=[(1,2),(2,1)]

// now we shrink it.
i=1 

m=[(1,1),(2,1)]

 0 1 2 3 4 
[1,2,1,2,3]
   i j 


i_bada=0


count=1+(i-i_bada+1)
     =3


4) j=3 

 0 1 2 3 4 
[1,2,1,2,3]
   i   j 


m=[(1,1),(2,2)]

// shrink it.

i=2 
m=[(1,1),(2,1)]

 0 1 2 3 4 
[1,2,1,2,3]
     i j 

i_bada=0

count=3+(i-i_bada+1)
     =6
5) j=4 

 0 1 2 3 4 
[1,2,1,2,3]
     i   j 

m=[(1,1),(2,1),(3,1)]

// its invalid

i=3


m=[(2,1),(3,1)]
 0 1 2 3 4 
[1,2,1,2,3]
       i j 

where i_bada=i =3


its valid now 

count=6+(i-i_bada+1)
     =7

Output -: 7.




Cpp 
Code:

Time -> O(N)
Space ->O(N)
int subarraysWithKDistinct(vector<int>& nums, int k) 
{
        int n=nums.size();
        unordered_map<int,int>m;
        int count=0;

        int i=0;
        int j=0;
        int i_bada=0;
        while(j<n)
        {
            m[nums[j]]++;

            // when unqiue element are greater than k
            while(m.size()>k)
            {
                m[nums[i]]--;
                if(m[nums[i]]==0)
                m.erase(nums[i]);
                i++;
                
                i_bada=i;
            }

            // shrinking the valid unqiue count=k 
            while(m[nums[i]]>1)
            {
                m[nums[i]]--;
                i++;
            }
            
            // smallest valid substring
            if(m.size()==k)
            count+=(i-i_bada+1);

            j++;
        }
        return count;
}