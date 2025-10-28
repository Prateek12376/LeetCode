class MedianFinder {
public:
    priority_queue<int>pqMax;
    priority_queue<int,vector<int>,greater<int>>pqMin;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        //insert
        if(pqMax.empty() || num<pqMax.top()){
            pqMax.push(num);
        }
        else{
            pqMin.push(num);
        }
        //balance
        if(pqMax.size()>pqMin.size()+1){
            pqMin.push(pqMax.top());
            pqMax.pop();
        }
        if(pqMin.size()>pqMax.size()+1){
            pqMax.push(pqMin.top());
            pqMin.pop();
        }
        
    }
    
    double findMedian() {
        if(pqMax.size()==pqMin.size()){
            if(pqMax.empty()){
                return 0;
            }
            else{
                double median = (pqMax.top()+pqMin.top())/2.0;
                return median;
            }
        }
        else if (pqMax.size() > pqMin.size()) {
            return pqMax.top();
        } else {
            return pqMin.top();
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */