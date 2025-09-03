class MyQueue {
    stack<int>s1,s2;
public:
    MyQueue() { }
    
    void push(int x) {
        s1.push(x);
    }
    
    int pop() {
        int elm;
        if(!s2.empty()){
            elm=s2.top();
            s2.pop();
        }
        else{
            while(s1.size()!=0){
                s2.push(s1.top());
                s1.pop();
            }
            elm=s2.top();
            s2.pop();
            return elm;
        }
        return elm;
    }
    
    int peek() {
        if(!s2.empty()){
            return s2.top();
        }
        else{
            while(s1.size()!=0){
                s2.push(s1.top());
                s1.pop();
            }
            return s2.top();
        }
        return s2.top();
    }
    
    bool empty() {
        if(s1.empty() && s2.empty()){
            return true;
        }
        else{
            return false;
        }
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */