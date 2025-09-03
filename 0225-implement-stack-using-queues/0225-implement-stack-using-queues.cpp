class MyStack {
    queue<int>q;
public:
    MyStack() {}
    
    void push(int x) {
        q.push(x);
        int size= q.size();
        for(int i=0;i<size-1;i++){
            q.push(q.front());
            q.pop();
        }
    }
    
    int pop() {
        int elm=q.front();
        q.pop();
        return elm;
    }
    
    int top() {
        return q.front();
    }
    
    bool empty() {
        if(q.size()==0){
            return true;
        }
        else return false;
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