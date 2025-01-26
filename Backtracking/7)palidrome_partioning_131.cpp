Time-: 1) generate all partitions -> O(2^N) there is 2 possibility either to form a new partition or not.
       2) for every partition -> check its palindrome or not ?
       3) O(2^n*n)

Space-:1) generate all partitions -> O(2^N) 
       2) make substring s1 O(n)
       3)O(2^n*n)

Code-:
bool isPalidrome(string &str)
{
        string s1=str;
        reverse(str.begin(),str.end());
        return (s1==str);
}

void helper(string s,int index,int n,vector<string>&v1,vector<vector<string>>&ans)
{
        if(index==n)
        {
            ans.push_back(v1);
            return ;
        }
        for(int i=index;i<n;i++)
        {
           string str=s.substr(index,i-index+1);
           if(isPalidrome(str))
           {
               v1.push_back(str);
               helper(s,i+1,n,v1,ans);
               v1.pop_back();
           }
        }
}
vector<vector<string>> partition(string s) {
        vector<vector<string>>ans;
        vector<string>v1;
        int n=s.length();
 
        helper(s,0,n,v1,ans);
        return ans;
}