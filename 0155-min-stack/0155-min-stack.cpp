class MinStack {   
public:
    stack<pair<int,int>> mS;
    MinStack() {  
    }
    void push(int val) {
        int new_min=mS.empty() ? val :min(val,mS.top().second);
        mS.push({val,new_min}); 
    }
    void pop() {
        mS.pop();
    }
    int top() {
        return mS.top().first;
    }
    int getMin() {
        return mS.top().second;   
    }
};
