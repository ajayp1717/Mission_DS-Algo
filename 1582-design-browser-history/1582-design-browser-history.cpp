class BrowserHistory {
public:
    stack<string>prev;
    stack<string> nxt;
    BrowserHistory(string homepage) {
        prev.push(homepage);
        nxt=stack<string>();
    }
    
    void visit(string url) {
        prev.push(url);
        nxt=stack<string>();
    }
    
    string back(int steps) {
        while(steps-- && prev.size()>1){
            nxt.push(prev.top());
            prev.pop();
        }
        return prev.top();
    }
    
    string forward(int steps) {
        while(steps-- && nxt.size()>0){
            prev.push(nxt.top());
            nxt.pop();
        }
        return prev.top();   
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */