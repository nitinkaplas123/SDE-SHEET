Solution 1-:
Steps-:
1)Using 2 for loops.

Code-:
int findMaximumXOR(vector<int>& nums) {
        int n=nums.size();
        int ans=0;
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                int val=nums[i]^nums[j];
                ans=max(ans,val);
            }
        }
        return ans;
}



Solution 2-:
Steps-:
1)Using trie and bit manipulation 

Code-:
class Solution {
    #define N 2
    struct trienode {
        int number;
        trienode* child[N];
        trienode(){
            for(int i=0;i<N;++i)
                child[i]=NULL;
        }
    };
    trienode *root;
    void TrieInsert(const int& no,const string& s){
        trienode* curr = root;
        int idx;
        for(int i=0;s[i]!='\0';++i){
            idx = s[i]=='0'?0:1;
            if(!curr->child[idx])
                curr->child[idx] = new trienode();
            curr = curr->child[idx];
        }
        curr->number=no;
    }
    int searchMaxInTrie(string candidate){
        trienode* curr = root;
        int idx;
        for(int i=0;candidate[i]!='\0';++i){
            idx = candidate[i]=='0'?1:0;
            if(curr->child[idx]){
                curr = curr->child[idx];
            } else {
                curr = curr->child[!idx];
            }
        }
        return curr->number;
    }
    string convert2string(int num,int size){
        string s;
        int len=0;
        while(num){
            if(num%2==0)
                s.push_back('0');
            else
                s.push_back('1');
            len+=1;
            num/=2;
        }
        for(;len<size;++len)
            s.push_back('0');
        reverse(s.begin(),s.end());
        return s;
    }
    void Int2String(vector<int>& nums,vector<string>& nos){
        int maxNo = *max_element(nums.begin(),nums.end());
        int size = maxNo>=1?log2(maxNo)+1:1;
        for(int num: nums)
            nos.push_back(convert2string(num,size));
    }
public:
    int findMaximumXOR(vector<int>& nums) {
        root = new trienode();//Initialize Trie

        vector<string> nos;
        Int2String(nums,nos);
        //cout<<"All strings\n";
        for(int i=0;i<nums.size();++i){
        //    cout<<nums[i]<<": "<<nos[i]<<"\n";
            TrieInsert(nums[i],nos[i]);
        }

        int maxXOR = 0;
        for(int i=0;i<nums.size();++i)
            maxXOR = max(maxXOR,nums[i]^searchMaxInTrie(nos[i]));
        return maxXOR;
    }
};



Java -:
