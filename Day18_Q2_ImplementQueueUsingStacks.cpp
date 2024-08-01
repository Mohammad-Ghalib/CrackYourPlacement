class MyQueue {
public:

    stack<int> in;
    stack<int> out;

    MyQueue() {
        
    }
    
    void push(int x) {
        in.push(x);
    }
    
    int pop() {
        if(!out.empty()){
            int temp = out.top();
            out.pop();
            return temp;
        }
        
        while(!in.empty()){
            out.push(in.top());
            in.pop();
        }
        int temp = out.top();
        out.pop();
        return temp;         
    }
    
    int peek() {
        if(!out.empty()) return out.top();
        
        while(!in.empty()){
            out.push(in.top());
            in.pop();
        }
        return out.top(); 
    }
    
    bool empty() {
        return in.empty() & out.empty();
    }
};