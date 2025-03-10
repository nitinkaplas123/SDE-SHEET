Solution 1-:
Steps:
1)Make all permutation and store it in vector of strings.
2)Now compare and find the largest number.




Solution 2-:
Steps-:
1)using compartor function.


eg. [3,30,9]

     a=3 b=30.
     a+b> b+a
     330>303    (correct)
     which means 330 will be at front. 


     a=330   b=9
    
    a+b > b+a.
     3309>9330n       false. 
     so swap it and then return. 

    9330 
    now its return 9330.

Steps-:
1)Convert the numbers interger into strings array.
2)Sort using comp function. 
3)Now our vector of strings are sorted in decending order (largest in left side and smallest on right side).
4)traverse the array from back to start.


Edges Case-:
[0,0]

ans -> ["0","0"]
after comp sorting
[0,0]

now concat -> "00"
bt answer is "0".

So here we put the base case 
if nums[0]=='0' which means largest element is 0 then smallest will also be th esmallest.

if(num[0]=='0')
return "0";


Time->o(Nlog(N))
Code:
static bool comp(string &a,string &b)
{
        return a+b>b+a;
}
string largestNumber(vector<int>& nums) {
        int n=nums.size();
        vector<string>ans;
        for(int i=0;i<n;i++)
        {
            ans.push_back(to_string(nums[i]));
        }

        sort(ans.begin(),ans.end(),comp);
        if(ans[0]=="0") return "0";
        string res="";
        for(int i=0;i<n;i++)
        {
            res+=ans[i];
        }
        return res;
}