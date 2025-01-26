Solution 1-:
Steps-:
1)using backtracking 

Diagram -:

                                              digits = "23"     2-> "abc" 3->"def"
                                              index,n,str
                                              f(0,2,"")
                                              s="abc"
                                    i=0                                  i=1                                                i=2
                                 f(1,2,"a")                             f(1,2,"b")                                      f(1,2,"c")
                        
 f(2,2,"ad")     f(2,2,"ae")   f(2,2,"af")                f(2,2,"bd")     f(2,2,"be")    f(2,2,"bf")          f(2,2,"cd")       f(2,2,"ce")     f(2,2,"cf")



Code-: Time->O(4^n) Space->O(N) -> for recursive call stack. 
void helper(string digits,int index,int n,unordered_map<char,string>&m,string &str,vector<string>&ans)
{
        if(index==n)
        {
            ans.push_back(str);
            return ;
        }
        string s=m[digits[index]];
        for(int i=0;i<s.length();i++)
        {
            str.push_back(s[i]);
            helper(digits,index+1,n,m,str,ans);
            str.pop_back();
        }
}

vector<string> letterCombinations(string digits) {
        vector<string>ans;
        int n=digits.length();
        if(n==0) return ans;
        unordered_map<char,string>m;
        m['2']="abc";
        m['3']="def";
        m['4']="ghi";
        m['5']="jkl";
        m['6']="mno";
        m['7']="pqrs";
        m['8']="tuv";
        m['9']="wxyz";
        string str="";
        int index=0;
        helper(digits,index,n,m,str,ans);
        return ans;
}



Time Complexity -:
Time Complexity Analysis:
Depth of recursion: The depth of recursion corresponds to the length of the input string, which is n.
Branching factor: For each digit, the number of characters it maps to varies, but it is at most 4 (for digits '7' and '9', which map to 4 characters). For all other digits, the number of characters is 3.
In the worst case (where every digit maps to 4 characters, like '7' or '9'), the branching factor is 4.

Total recursive calls: In the worst case, at each level of recursion, the function branches 4 times. Hence, the total number of function calls can be modeled as:
4n 
 if each digit maps to 4 characters)4 n
 if each digit maps to 4 characters
Thus, the overall time complexity of the backtracking algorithm is O(4^n)
O(4n) in the worst case.