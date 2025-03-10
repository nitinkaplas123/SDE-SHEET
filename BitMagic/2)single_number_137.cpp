Solution 1-:
Steps-:
1)using map.



Solution 2-:
Steps-:
arr -> [6,5,5,4,5,6,6]

1)There is only one element which occur single time rest all are occur 3 times.

Using bit magic -:

32 .. 2 1 0     there are 32 bits.
6  -> 1 1 0
5  -> 1 0 1
5  -> 1 0 1
4  -> 1 0 0 
5  -> 1 0 1 
6  -> 1 1 0
6  -> 1 1 0
      7 3 3

0th bit -> set bits -> 3    -> 0
1st bit -> set bits -> 3    -> 0 
2nd bit -> set bits -> 7    -> 1 at bit 2 single number ke bit is set. 

ans+= 2^2
ans=4.

Note -: if all numbers are 3 times in array except one number.
        can we say that if no. of set bits is multiple of 3 then there single number ke bit is unset. yes.


Time->O(N)
Space->O(1)
Code-:
int singleNumber(vector<int>& nums) {
        int n=nums.size();
        int ans=0;
        for(int i=0;i<32;i++)
        {
            int count=0;
            for(int j=0;j<n;j++)
            {
                if(((1<<i)&nums[j])!=0)
                count++;
            }
            if(count%3!=0)
            ans+=(1<<i);
        }
        return ans;
}

