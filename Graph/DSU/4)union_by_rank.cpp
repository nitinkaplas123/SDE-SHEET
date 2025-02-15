
Time ->O(log(n))
Space ->O(log(n))
Code-:
int find(int par[],int a)
{
        if(par[a]==a)
        return a;
        else
        return find(par,par[a]);
}
void union_( int a, int b, int par[], int rank1[]) 
{
        int a_rep=find(par,a);
        int b_rep=find(par,b);
        
        if(a_rep==b_rep) return ;
        
        if(rank1[a_rep]<rank1[b_rep])
        par[a_rep]=b_rep;
        else if(rank1[a_rep]>rank1[b_rep])
        par[b_rep]=a_rep;
        else
        {
            par[a_rep]=b_rep;
            rank1[b_rep]++;
        }
}
    
//Function to check whether 2 nodes are connected or not.
bool isConnected(int x,int y, int par[], int rank1[])
{
    return (find(par,x)==find(par,y));
}