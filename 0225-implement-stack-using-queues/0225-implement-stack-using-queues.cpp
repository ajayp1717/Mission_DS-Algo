class MyStack {
public:
    queue<int>q;
    MyStack() {
        
    }
    
    void push(int x) {
        q.push(x);
        int k=q.size();
        while(--k){
            q.push((int)q.front());
            q.pop();
        }
    }
    
    int pop() {
        int el=q.front();
        q.pop();
        return el;
        
    }
    
    int top() {
        return (int) q.front();
    }
    
    bool empty() {
        return q.empty(); 
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */