Time-:O(N*L) where N is the no. of strings and L is the len of string.
Space->O(N*L) to build the trie 

Code-:
class TrieNode
{
    public:
    TrieNode* children[26];
    int childCount;
    bool isLeaf;

    TrieNode()
    {
        for(int i=0;i<26;i++)
        {
            children[i]=NULL;
        }
        childCount=0;
        isLeaf=false;
    }
};
class Solution {
public:
void insert(TrieNode* root,string str)
{
        TrieNode* curr=root;
        for(char ch:str)
        {
            int index=ch-'a';
            if(curr->children[index]==NULL)
            {
                curr->children[index]=new TrieNode();
                curr->childCount++;
            }
            curr=curr->children[index];
        }
        curr->isLeaf=true;
}

string search(TrieNode *root, string& s) 
{
      TrieNode* curr = root;
      int i = 0;
    
      while (curr->childCount==1 && curr->isLeaf==false) 
      {
          int idx = s[i] - 'a';
          i++;
          curr = curr->children[idx];
      }
      return s.substr(0, i);
}

string longestCommonPrefix(vector<string>& strs) {
        int n=strs.size();
        TrieNode* root=new TrieNode();
        for(int i=0;i<n;i++)
        {
            insert(root,strs[i]);
        }
       
        return search(root,strs[0]);
}

Java Code-:
class TrieNode {
    TrieNode[] children;
    int childCount;
    boolean isLeaf;

    public TrieNode() {
        children = new TrieNode[26];
        childCount = 0;
        isLeaf = false;
    }
}

public class Solution {
    
    // Insert a string into the Trie
    public void insert(TrieNode root, String str) {
        TrieNode curr = root;
        for (char ch : str.toCharArray()) {
            int index = ch - 'a';
            if (curr.children[index] == null) {
                curr.children[index] = new TrieNode();
                curr.childCount++;
            }
            curr = curr.children[index];
        }
        curr.isLeaf = true;
    }

    // Search for the longest common prefix
    public String search(TrieNode root, String s) {
        TrieNode curr = root;
        int i = 0;

        // Traverse the Trie until there is a branch (more than one child) or we reach a leaf
        while (curr.childCount == 1 && !curr.isLeaf) {
            int idx = s.charAt(i) - 'a';
            i++;
            curr = curr.children[idx];
        }
        return s.substring(0, i);
    }

    // Main function to find the longest common prefix of a list of strings
    public String longestCommonPrefix(String[] strs) {
        int n = strs.length;
        TrieNode root = new TrieNode();

        // Insert all the strings into the Trie
        for (int i = 0; i < n; i++) {
            insert(root, strs[i]);
        }

        // Search for the longest common prefix in the Trie
        return search(root, strs[0]);
    }
}
