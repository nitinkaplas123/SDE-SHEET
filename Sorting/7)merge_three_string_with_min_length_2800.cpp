Steps:
1)Here we have 3 strings to merge which is a,b,c.
2)So here we have 3! permuation out of which we have to find the minLenfth and which 
  if there is 2 strings of same len then give me lexiographic smallest.
3)So we create permuation and store it in arrangements vector.
  {a,b,c}  -> this of vector<string>

  so thats why we create vector<vector<string>>arrangemenets.

4) We run a loop of arragemenets.
   arr-> {a,b,c}

   suppose a="abc"   b="bca"   c="aaa"

now merge accordinly.

There is 3 cases:
string s=""     string t=""
// Case1: when t is fully inside s.
for eg. s="abc"   b="bc"

Code:
if(s.find(t)!=string::npos)
return s;

return s immeditaley.


//Case2 : when t is partially inside s.
for eg. s="abc"   t="bca"

merge -> "abca"
return this.

here we are finding from suffix of s, and prefix of t.

s="abc"   t="bca"

i=1 s.substr(s.length()-i)==s.substr(0,i)
    s="c"   t="b"

i=2 s="bc"  t="bc"

overlap=2.


## now at the end we not return skipped merge of t 
s+t.substr(maxOverlap)

maxOverlap=2 
which means s+t(2)  t(2)->means "a"  -> startIndex=2, lenfth ->till the last.





Time Complexity : O(3! * N^2)
Space Complexity: O(3!)

Code:
string mergeStrings(string s,string t)
{
        if(s.find(t)!=string::npos)
        return s;

        int maxOverlap=0;
        int max=min(s.length(),t.length());

        for(int i=1;i<=max;i++)
        {
            if(s.substr(s.length()-i)==t.substr(0,i))
            maxOverlap=i;
        }
        return s+t.substr(maxOverlap);
}
string minimumString(string a, string b, string c) {
        vector<vector<string>>arrangements={
            {a,b,c},{a,c,b},{b,a,c},{b,c,a},{c,a,b},{c,b,a}
        };

        string ans=a+b+c;
        for(auto arr:arrangements)
        {
            string currStr=arr[0];
            for(int i=1;i<3;i++)
            {
                currStr=mergeStrings(currStr,arr[i]);
            }
            if(currStr.length()<ans.length() || (currStr.length()==ans.length() and ans>currStr))
            ans=currStr;
        }
        return ans;
}