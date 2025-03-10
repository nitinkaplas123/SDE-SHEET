Solution 1-:
Steps-:
1)using map.



Solution 2-:
Steps-:
1)make xor of all. -> val
2)find the index of set bit of val.
  if at index -> set bit in val means at that index we have combination of 1 and 0.
3)Now we run a loop on array and check bit at index in every value set or not.
  make 
  set   -> 
  unset ->

4)return {set,unset};


Time  ->  O(N)
Space ->  O(1)
Code-:
vector<int> singleNumber(vector<int>& nums) {
        int n=nums.size();
        //xor
        int val=0;
        for(int i=0;i<n;i++){
            val^=nums[i];
        }
      

        // set bit 
        int index;
        for(int i=0;i<32;i++){
            if(((1<<i)&val)!=0)
            {
                index=i;
                break;
            }
        }

        int set=0;
        int unset=0;
        for(int i=0;i<n;i++){
            if(((1<<index)&nums[i])!=0)
            set^=nums[i];
            else
            unset^=nums[i];
        }
        return {set,unset};
}