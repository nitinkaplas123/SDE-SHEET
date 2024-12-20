Solution 1-:
Steps-:
1) here we are using 2 loops.
2) we use hashset for storing unique charcter if we find the char in set then we store the max_length in it.

edge cases-:


ans=0;
str="au"
1)set[a,u]

here no duplicate char is there so we return ans which is 0 which is wrong.

Solution is we have to make a varible res where we also store the max_size of hashset which tell us that the 
max unique char in hashset.


Code-: Time->O(n^2) Space->O(N)
int lengthOfLongestSubstring(string s) {
        int n=s.length();
        int ans=INT_MIN;
        if(n==0 || n==1) return n;
        int res=0;
        for(int i=0;i<n;i++)
        {
            unordered_set<int>st;
            for(int j=i;j<n;j++)
            {
                if(st.find(s[j])!=st.end())
                {
                    ans=max(ans,j-i);
                    break;
                }
                else
                st.insert(s[j]);
            }
            int size=st.size();
            res=max(res,size);
        }
        ans=max(ans,res);
        return ans;
}



Solution 2-:
Steps-:
1)using two pointer low and high
2)there is 2 cases-:
2.1 -> if s[high] is present in hashset then we have to store than answer and apply while loop 
       in which we delete the elements from hashset using low pointer.
2.2 -> else it means the s[high] is not present in set so we have to add it into set.

3)at last if we have all unique elements eg. s="ab"
  so all char are into hashset so we =>
  ans=max(ans,s.size());
  return ans;


Code-: Time->O(N) Space->O(N)
int lengthOfLongestSubstring(string s) {
        int n=s.length();
        unordered_set<char>set;
        int i=0;
        int j=0;
        int ans=0;
        while(j<n)
        {
           while(set.find(s[j])!=set.end())
           {
              set.erase(s[i]);
              i++;
           }
           set.insert(s[j]);
           ans=max(ans,j-i+1);
           j++;
        }
        return ans;
}



 Solution 3-:
 Steps-:
 1)Here we do two pointers approach low and high.
 2)we make a array count[256] ={0} as freq.
 3)now we firstly add the char into count and increases its freq.
 4)if count[s[high]]>1 which means we encounter with duplicate value 
   here we decrease the freq using low 
 5)else if its unique charcter then we have to store the answer into ans variable.

 
Code-:
int lengthOfLongestSubstring(string s) {
         int n=s.length();
         int count[256]={0};

         int i=0;
         int j=0;
         int ans=0;
         while(j<n)
         {
             while(count[s[j]]>0)
             {
                count[s[i]]--;
                i++;
             }
             count[s[j]]++;
             ans=max(ans,j-i+1);
             j++;
         }
         return ans;
}