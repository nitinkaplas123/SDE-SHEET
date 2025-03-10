Solution 1-:
Steps-:
1)use the same idea as of add 1 to linked list.

Code-:
vector<int> plusOne(vector<int>&nums) {
        int n=nums.size();
        reverse(nums.begin(),nums.end());
        int carry=1;
        for(int i=0;i<n;i++)
        {
            int sum=nums[i]+carry;
            nums[i]=(sum%10);
            carry=(sum/10);
        }
        if(carry!=0)
        nums.push_back(carry);
        reverse(nums.begin(),nums.end());
        return nums;
}



Solution 2:
Steps:
1)Without reverse function.

Code:
vector<int> plusOne(vector<int>& digits) {
        int n=digits.size();
        
        int sum=digits[n-1]+1;
        digits[n-1]=(sum%10);
        int carry=(sum/10);
        
        for(int i=n-2;i>=0;i--)
        {
            sum=digits[i]+carry;
            digits[i]=(sum%10);
            carry=(sum/10);
        }
        if(carry!=0)
        digits.insert(digits.begin(),carry);
        return digits;
    }