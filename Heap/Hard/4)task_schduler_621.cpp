//Approach (Heap + Greedy)
//T.C : O(n)
//S.C : O(1)


 
tasks = ["B","C","D","A","A","A","A","G"] and n=1 

using minHeap -> B->C->D->G->A->idle->A->idle->A->idle->A    -> o/p -: 11

using maxHeap -> A->B->A->C->A->D->A->G    -> O/P -: 8 


Steps:
1)Make a map of key,value.
2)Add its frequency in a maxHeap.  (the higher frequency charcter will be used first as i want least length means, dont want idle)
3)Now want to gap of atleast n means want a n+1 length in a one go. so thats why we are using a loop of n+1.
case1 : if pq is finished means we just have to add the remaning characters in a list
case2 : if pq is not finished -> then we want (n+1) characters in one go, to make a gap in similar characters.
        

tasks = ["B","C","D","A","A","A","A","G"] and n=1 
dry run:

time=0
1) frequency -:  A ->4, B->1 , C->1, D->1, G->1
2) add all in pq.
   4
 1    1 

1   1 


// Iteration 1:   run 2 times
pq -> 1,1,1      
   temp={3,0}

   time=2

A->B

// Iteration 2:  run 2 times
add all temp in pq except 0
pq -> {3,1,1,1}      

 temp={2,0}

 time=2+2=>4

 A->B->A->C


// Iteration 3:  run 2 times
add all temp in pq except 0
pq -> {2,1,1}

temp=>{1,0}

time=2+2+2 -> 6 

A->B->A->C->A->D

// Iteration 4:  run 2 times
add all temp in pq except 0
pq -> {1,1}

temp=>{0,0}

here pq is empty -> 
so add the temp.size() in time which is 2.
return time=2+2+2+2 -> 8 


final task completion.
// A->B->A->C->A->D->A->G





Time -> O(nlog(k))    where n times we traverse and k is the unique freq which we added in pq using map.
Space ->O(k)


Code-:
int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char,int>m;
        for(auto ch:tasks)
        {
            m[ch]++;
        }

        priority_queue<int,vector<int>,greater<int>>pq;
        for(auto x:m)
        {
            pq.push(x.second);
        }

        int time=0;
        vector<int>temp;
        while(!pq.empty())
        {
            for(int i=1;i<=n+1;i++)
            {
                if(!pq.empty())
                {
                    temp.push_back(pq.top()-1);
                    pq.pop();
                }
            }

            for(int i=0;i<temp.size();i++)
            {
                if(temp[i]>0)
                pq.push(temp[i]);
            }
            

            if(pq.empty())
            return time+temp.size();
            else
            time+=n+1;
            temp.clear();
        }
        return time;
    }