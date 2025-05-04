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
        int ans=0;
        unordered_set<char>set;
        int low=0;
        int high=0;
        while(high<n)
        {
            if(set.find(s[high])==set.end())
            {
                set.insert(s[high]);
                ans=max(ans,high-low+1);
                high++;
            }
            else
            {
               set.erase(s[low]);
               low++;
            }
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
        int ans=INT_MIN;

        unordered_map<int,int>m;
        int i=0;
        int j=0;
        while(i<n)
        {
            m[s[i]]++;
            if(m[s[i]]>1)
            {
                while(m[s[i]]>1)
                {
                    m[s[j]]--;
                    j++;
                }
            }
            ans=max(ans,i-j+1);
            i++;
        }
        return (ans==INT_MIN)?0:ans;
}