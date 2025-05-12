Whats the task?
You’re given a palindrome string. You must:

Replace exactly one character with any lowercase English letter.

The new string must NOT be a palindrome.

Among all such non-palindromic strings, return the lexicographically smallest one.


Case1 :
s="a" 
1)String having length 1 we cannot make a non-palindrome.

return "";

Case2:

s="aaaa"
this is smallest palindrome of size 4.

but we have to create smallest among non-palidrome.

return "aaab"

Case3:

s="abcd"

from starting when we see its not 'a' then making it 'a' and return immediately.

Time Complexity: O(N)
Space ->O(1)
Code:
string breakPalindrome(string palindrome) {
        int n=palindrome.length();
        if(n==1) return "";

        for(int i=0;i<n/2;i++)
        {
            if(palindrome[i]!='a')
            {
                palindrome[i]='a';
                return palindrome;
            }
        }
        palindrome[n-1]='b';
        return palindrome;
}