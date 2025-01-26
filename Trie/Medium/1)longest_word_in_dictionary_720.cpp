Reference -> https://www.youtube.com/watch?v=MbvGOab6Sfg&t=750s


Solution 1-:

Question-:
1)Find the word in a vector of string where all the prefix of word is present in my vector of strings.
for eg. 
words = ["w","wo","wor","worl","world"]

answer -> world.
prefix of world is => w,wo,wor,worl,world. 
if u see all the prefix of world is present in vector. 
2)we have to return the longest length string those all prefix is present in vector -> so here answer is world.

3)if there is 2 word those having same length then return the smallest string in terms of lexigrpahic order.
for eg. 
words = ["a","banana","app","appl","ap","apply","apple"]

sol-: apply and apple.
both having same length.

apple <apply 
return apple.


Steps-:
1)here first we add all the words in vectors. 
2)now we run a loop over every word and in every word we make all the prefix of word and check if its present in set or not.
  if any any point its not present in set return false.
3)if all the prefix is present then store the max of it in -> len-> length of the string and index-> word in a vector.



Time-> O(n*length_of_word)
Space->O(N) where n is the no. of words in a vector.
Code-: 
string longestWord(vector<string>& words) {
        int n=words.size();
        unordered_set<string>s;

        for(int i=0;i<n;i++)
        {
            s.insert(words[i]);
        }
        
        int index=0;
        int len=0;
        for(int i=0;i<n;i++)
        {
            string word=words[i];
            int j;
            for(j=0;j<word.length();j++)
            {
                string str=word.substr(0,j+1);
                if(s.find(str)!=s.end())
                continue;
                else
                break;
            }
            if(j==word.length())
            {
                if(len<word.length())
                {
                    index=i;
                    len=word.length();
                }
                else if(len==word.length())
                {
                    if(words[index]>word)
                    index=i;
                }
            }
        }
        return (len==0)?"":words[index];
}



Solution 2-:
Steps-: 
1)Here i insert all the words in a trie data structure -: Time-> O(n*l) Where n is the no. of words and l is the max length of any word.
  where we have -:
  1) each charcter has 26 length. 
  2) isEnd=true/false. here we tell the word is end at that character.
  3) at each of the character we added a string at that node as well.

2) now using dfs we find the max word those all the prefix is present.
   for that if we make a diagram at every charcter node its isEnd=true.
   only in that case we can say that its has all the prefix of the word.


Time->O(N*L) for insertion + O(N*L) for dfs ->O(N*L)
Space->O(N*L) for making trie + O(L) for recursive call stack.

Code-:
class TrieNode
{
    public:
    TrieNode* children[26];
    bool isEnd;
    string str;
    TrieNode()
    {
        isEnd=false;
        for(int i=0;i<26;i++)
        {
            children[i]=NULL;
        }
    }
};

class Solution {
public:
    void insert(TrieNode* root,string word)
    {
        TrieNode* curr=root;
        for(int i=0;i<word.length();i++)
        {
            int index=word[i]-'a';
            if(curr->children[index]==NULL)
            curr->children[index]=new TrieNode();
            curr=curr->children[index];
        }
        curr->isEnd=true;
        curr->str=word;
    }
    void dfs(TrieNode* curr,string &ans)
    {
        for(int i=0;i<26;i++)
        {
            if(curr->children[i]!=NULL and curr->children[i]->isEnd==true)
            {
                if(ans.length()<curr->children[i]->str.length())
                ans=curr->children[i]->str;
                else if(ans.length()==curr->children[i]->str.length())
                {
                    if(curr->children[i]->str<ans)
                    ans=curr->children[i]->str;
                }
                dfs(curr->children[i],ans);
            }
        }
        return ;
    }
    string longestWord(vector<string>& words) {
        int n=words.size();
        TrieNode* root=new TrieNode();
        for(int i=0;i<n;i++)
        {
           insert(root,words[i]);
        }
        string ans="";
        dfs(root,ans);
        return ans;
    }
};



Java Code-:
class TrieNode {
    TrieNode[] children;
    boolean isEnd;
    String str;

    TrieNode() {
        children = new TrieNode[26]; // Array for 26 lowercase letters
        isEnd = false; // Indicates if this is the end of a valid word
        str = ""; // Stores the word at this node
    }
}

class Solution {
    public void insert(TrieNode root, String word) {
        TrieNode current = root;

        // Traverse each character in the word
        for (char ch : word.toCharArray()) {
            int index = ch - 'a';
            if (current.children[index] == null) {
                current.children[index] = new TrieNode();
            }
            current = current.children[index];
        }

        // Mark the end of the word and store the word
        current.isEnd = true;
        current.str = word;
    }

    public void dfs(TrieNode current, String ans[]) {
    for (int i = 0; i < 26; i++) 
    {
        if (current.children[i] != null && current.children[i].isEnd) 
        {
            // Check if the current word should update the answer
            if (ans[0].length() < current.children[i].str.length()) 
            ans[0] = current.children[i].str;
            else if (ans[0].length() == current.children[i].str.length()) 
            {
                if(current.children[i].str.compareTo(ans[0]) < 0)
                ans[0] = current.children[i].str;
            }
            // Continue the DFS
            dfs(current.children[i], ans);
        }
    }
}

public String longestWord(String[] words) {
    TrieNode root = new TrieNode();

    // Insert all words into the Trie
    for (String word : words) {
        insert(root, word);
    }

    // Use a String array to store the answer (mutable reference)
    String[] ans = {""};

    // Perform DFS to find the longest word
    dfs(root, ans);

    return ans[0];
}

}