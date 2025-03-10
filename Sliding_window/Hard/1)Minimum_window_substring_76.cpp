Solution 1-:

-> Here we have given two string s and t we have to find the minimum window in s where all 
   the elements of t will be there.


Steps-:
1)First a fall we make a map where we add t string val,freq in it.
2)Make a count variable -> m.size()
3)Now using 2 pointer approach (i,j) 
  where i is at starting point and j is at ending position where we have all the elements of t in 
  that window(from i to j).Now we store the starting point and len of the string in it.
4)we reach to possible answer now its time to compress from left side to right side.
   Below code do it.

Case 1-:
when we go from to right side using j -> means we take the window of it for that we 
decreases the count and m[s[t]]--. 
if(count==0) means we have a window from (i,j) of string s which have all char of t.

Case 2-:
when we have count==0 we compress the string s from left to right using i variable.
where we add the freq into map.
m[s[i]]++ 
if(m[s[i]]>0) this line tells us that if we have current char of s in it. now we are 
not incluing into our window thats why 
count++ kr rahe ha.

          if(count==0)
           {
               while(count==0)
               {
                   if(len>j-i+1)
                   {
                       start=i;
                       len=j-i+1;
                   }

                   m[s[i]]++;
                   if(m[s[i]]>0)
                   count++;

                   i++;
               }
           }

5)Do dry run for clear understanding.



Code-: Time->O(2*n) -> O(n)   
string minWindow(string s, string t) {
        unordered_map<char,int>m;
        for(int i=0;i<t.length();i++)
        {
            m[t[i]]++;
        }

        int i=0;
        int j=0;
        int start=0;
        int len=INT_MAX;
        int n=s.length();
        int count=m.size();

        while(j<n)
        {
           m[s[j]]--;
           if(m[s[j]]==0)
           count--;

           if(count==0)
           {
               while(count==0)
               {
                   if(len>j-i+1)
                   {
                       start=i;
                       len=j-i+1;
                   }

                   m[s[i]]++;
                   if(m[s[i]]>0)
                   count++;

                   i++;
               }
           }
           j++;
        }
        return (len==INT_MAX)?"":s.substr(start,len);
    }