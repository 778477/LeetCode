/**
 Status: Accepted
 Runtime: 0 ms
 Submitted: 2 years, 2 months ago
*/

class Stack {
public:
    void push(int x) {
        size_t cnt = q.size();
        q.push(x);
        while (cnt--) {
            q.push(q.front());
            q.pop();
        }
    }
    void pop() {
        q.pop();
    }
    int top() {
        return q.front();
    }
    bool empty() {
        return q.empty();
    }
private:
    queue<int> q;
};
