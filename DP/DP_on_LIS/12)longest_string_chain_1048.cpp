Solution 1-:
Steps-:
1)Sort the array.
2)Do the same concept of lis.
3)logic -> diff of 2 strings will be 1.   + isValid. 
4)return maxx.
   



Time->O(N^2*len_of_word).
Space->O(N)
Code-:
class Solution {
public:
bool static comp(string &a,string b)
{
        if(a.size()==b.size())
        return a<b;
        else
        return a.size()<b.size();
}
bool isValid(string &s1,string &s2)
{
        int i=0;
        int j=0;
        int n1=s1.length();
        int n2=s2.length();
        int count=0;
        while(i<n1 and j<n2)
        {
            if(s1[i]==s2[j])
            {
                i++;
                j++;
            }
            else
            {
               j++;
               count++;
            }
        }
        return (count<=1);
}
int longestStrChain(vector<string>& words) {
        int n=words.size();
        sort(words.begin(),words.end(),comp);
        
     
        vector<int>temp(n,1);
        int maxx=1;
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(words[i].size()==1+words[j].size() and isValid(words[j],words[i]))
                {
                   if(temp[i]<1+temp[j])
                   temp[i]=1+temp[j];
                }
            }
            maxx=max(maxx,temp[i]);
        }
        return maxx;
    }
};


