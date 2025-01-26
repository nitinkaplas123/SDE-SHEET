Code-:
void insert(struct TrieNode *root, string key)
{
    TrieNode* curr=root;
    for(int i=0;i<key.length();i++)
    {
        int index=key[i]-'a';
        if(curr->children[index]==NULL)
        curr->children[index]=new TrieNode();
        curr=curr->children[index];
    }
    curr->isLeaf=true;
}
        
//Function to use TRIE data structure and search the given string.
bool search(struct TrieNode *root, string key) 
{
    TrieNode* curr=root;
    for(int i=0;i<key.length();i++)
    {
        int index=key[i]-'a';
        if(curr->children[index]==NULL) return false;
        curr=curr->children[index];
    }
    return (curr->isLeaf);
}



