class MinStack {
    stack<long long>st;
    long long curr_min=LLONG_MAX;
public:
    MinStack() {}
    
    void push(long long val) {
        if(st.empty()){
            curr_min=val;
            st.push(val);
        }
        else{
            if(val>=curr_min){
                st.push(val);
            }
            else{
                st.push(2*val-curr_min);
                curr_min=val;
            }
        }
    }
    
    void pop() {
        if(st.empty()){
            return;
        }
        long long x= st.top();
        st.pop();
        if(x<curr_min){
            curr_min= 2*curr_min- x;
        }
    }
    
    long long top() {
        if(st.empty()){
            return -1 ;
        }
        long long x=st.top();
        if(x>=curr_min){
            return x;
        }
        else{
            return curr_min;
        }
    }
    
    long long getMin() {
        if(curr_min==LLONG_MAX){
            return -1;
        }
        else{
            return curr_min;
        }
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */