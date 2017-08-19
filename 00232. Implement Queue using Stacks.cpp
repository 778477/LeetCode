/**
 Status: Accepted
 Runtime: 0 ms
 Submitted: 1 year, 3 months ago
*/
class Queue {
public:
    // Push element x to the back of queue.
    void push(int x) {
        s.push(x);
    }
    
    // Removes the element from in front of queue.
    void pop(void) {
        while(!s.empty()){
            o.push(s.top());
            s.pop();
        }
        
        o.pop();
        
        while(!o.empty()){
            s.push(o.top());
            o.pop();
        }
    }
    
    // Get the front element.
    int peek(void) {
        while(!s.empty()){
            o.push(s.top());
            s.pop();
        }
        
        int ans = o.top();
        
        while(!o.empty()){
            s.push(o.top());
            o.pop();
        }
        
        return ans;
    }
    
    // Return whether the queue is empty.
    bool empty(void) {
        return s.empty();
    }
private:
    stack<int> s;
    stack<int> o;
};
