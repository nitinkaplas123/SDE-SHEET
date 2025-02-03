Solution 1-:
Steps-:
1) make a vector.

Code-:
class MedianFinder {
public:
    vector<int>v;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        v.push_back(num);
        sort(v.begin(),v.end());
    }
    
    double findMedian() {
        int n=v.size();
        if(n%2!=0)
        return (double)v[n/2];
        else
        {
            return (double) (v[n/2] + v[n/2-1])/2.0;
        }
    }
};



Solution 2-:
Steps-:
1) Make two heap -> left_max_heap and right_min_heap.
2) if n is even -> then equally distribute.
   if n is odd -> 1 element is more in left side.

3) if left.size()==empty || if num is smaller than top of left_max. 
   add it into left_max.
   else
   add it in right.min.

Case1 -:
if left.size()<right.size()
take the top value of right_min_heap and add it into left_min.

Cas2-: if(left.size()-right.size()>1)  which means (left.size()==right.size()) || left>right+1 but not more than 1.
if this case.
take the top value of left and put it into right.

4)Median.
  if n is odd 
  return left.top();
  if n is even.
  return (left.top()+right.top())/2.0;
  

//T.C : The overall time complexity is O(log N) for the addNum method and O(1) for the findMedian method.
//S.C : O(N).

Code-:
class MedianFinder {
public:
    priority_queue<int>left_max_heap;
    priority_queue<int,vector<int>,greater<int>>right_min_heap;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(left_max_heap.empty()==true || num<left_max_heap.top())
        left_max_heap.push(num);
        else
        right_min_heap.push(num);
        
        int left=left_max_heap.size();
        int right=right_min_heap.size();
        if(left<right)
        {
            left_max_heap.push(right_min_heap.top());
            right_min_heap.pop();
        }
        else if((left-right)>1)
        {
             right_min_heap.push(left_max_heap.top());
             left_max_heap.pop();
        }
    }
    
    double findMedian() {
        int n1=left_max_heap.size();
        int n2=right_min_heap.size();
        int n=n1+n2;
        if(n%2!=0)
        return left_max_heap.top();
        else
        return (left_max_heap.top()+right_min_heap.top())/2.0;
    }
};