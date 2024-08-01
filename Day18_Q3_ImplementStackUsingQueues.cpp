class MyStack {
public:
    queue<int> q;

    MyStack() {
        
    }
    
    void push(int x) {
        q.push(x);
        int n = q.size();

        for(int i=1; i<n; i++){
            q.push(q.front());
            q.pop();
        }
    }
    
    int pop() {
        int temp = q.front();
        q.pop();
        return temp;
    }
    
    int top() {
        return q.front();
    }
    
    bool empty() {
        return q.empty();
    }
};