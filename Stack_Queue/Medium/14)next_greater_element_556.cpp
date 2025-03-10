Solution 1-:
Steps-;
1)using same as next_permutation approach.

Case1-:
[2,1] -> [1,2] 

but here we need greater if not possible return -1.
if(ori>=ans) return -1;


Case2-: 
[INT_MAX] -> next greater of it 
so ans>INT_MAX 
but question said u will be within the limit 
return -1.

Code-:
int nextGreaterElement(int n) {
        string str=to_string(n);
        int len=str.length();

        int index=0;
        for(int i=len-2;i>=0;i--)
        {
            if(str[i]<str[i+1])
            {
                index=i;
                break;
            }
        }
       

        for(int i=len-1;i>=0;i--)
        {
            if(str[i]>str[index])
            {
                swap(str[i],str[index]);
                index++;
                break;
            }
        }

        int low=index;
        int high=len-1;
        while(low<high)
        {
            swap(str[low],str[high]);
            low++;
            high--;
        }

        long long int ans=stoll(str);
        long long int ori=(long long)n;
        if(ans<=ori) return -1;
        if(ans>INT_MAX) return -1;
        return (int)ans;
}