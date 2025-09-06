class StockSpanner {
public:
    stack<pair<int,int>>st;
    int index=-1;
    StockSpanner() {}
    
    int next(int price) {
        index+=1;
        while(!st.empty() && st.top().first<=price){
            st.pop();
        }
        int prevS_I;
        if(st.empty()){
            prevS_I=-1;
        }
        else{
            prevS_I=st.top().second;
        }
        int ans= index-prevS_I;
        st.push({price,index});
        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */