Solution 1-:

Question -:
1)I want smallest number after removing k digits.

Intution-:
1)we need smaller digits at the start.

Case 1-:
if(number of digits==k)  
means we have to remove all the digits.
return "0" 

Case2-:
eg. 
str="100100" k=1
If after k removal our 
str="00100"
in this case we have to ignore the starting zeros.

ans="100";

Steps-:
1)remove the element from the back of the string if back>nums[i]
  ans.pop_back()
2)if the element is smaller than the back element then add to the ans string.

note-: 
1)do not add the starting digit as zero 
   if(ans.length() || num[i]!='0')
   ans.push_back(num[i]);


Code-: Time->O(N) Space->O(1)
string removeKdigits(string num, int k) {
        int n=num.length();
        string ans="";
        for(int i=0;i<n;i++)
        {
            while(ans.size()!=0 and ans.back()>num[i] and k)
            {
                ans.pop_back();
                k--;
            }
            if(ans.length() || num[i]!='0')
            ans.push_back(num[i]);
        }
        
        while(ans.size()!=0 and k)
        {
            ans.pop_back();
            k--;
        }
        return (ans=="")?"0":ans;
}