//T.C : The overall time complexity is O(log N) for the addNum method and O(1) for the findMedian method.
//S.C : O(N).

Code-:
class MedianFinder {
public:
    priority_queue<int> left_max_heap; 
    priority_queue<int, vector<int>, greater<int>> right_min_heap; 
    
    MedianFinder() {
        
    }
    
    void addNum(int num) 
    {
        if(left_max_heap.empty() || num < left_max_heap.top())
        left_max_heap.push(num);
        else 
        right_min_heap.push(num);
        
        int left=left_max_heap.size();
        int right=right_min_heap.size();

        if(abs(left-right)>1) {
            right_min_heap.push(left_max_heap.top());
            left_max_heap.pop();
        } 
        else if(left_max_heap.size() < right_min_heap.size()) {
            left_max_heap.push(right_min_heap.top());
            right_min_heap.pop();
        }
    }
    
    double findMedian() {
        if(left_max_heap.size() == right_min_heap.size()) {
            return (double)(left_max_heap.top()+right_min_heap.top())/2;
        }
        return left_max_heap.top();
    }
};