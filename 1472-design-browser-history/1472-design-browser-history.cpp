class BrowserHistory {
public:
    struct Node{
        string val;
        Node* next;
        Node* prev;
    public:
        Node(string val1 , Node* forward, Node* backward){
            val=val1;
            next=forward;
            prev=backward;
        }
        Node(string val1){
            val=val1;
            next=NULL;
            prev=NULL;
        }
    };
    

    Node* currP;
    BrowserHistory(string homepage) {
        Node* newN = new Node(homepage);
        currP=newN;
    }

    
    void visit(string url) {
        Node* nextNode = new Node(url);
        currP->next=nextNode;
        nextNode->prev=currP;
        currP = currP->next;
    }
    
    string back(int steps) {
        while(steps>0){
            if(currP->prev!=NULL){
                currP=currP->prev;
            }
            else{
                break;
            }
            steps--;
        }
        return currP->val;
    }
    
    string forward(int steps) {
        while(steps>0){
            if(currP->next!=NULL){
                currP=currP->next;
            }
            else{
                break;
            }
            steps--;
        }
        return currP->val;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */