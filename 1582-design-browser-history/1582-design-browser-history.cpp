class BrowserHistory {
public:
    struct Node{
        string val;
        Node* forward;
        Node* back;
        public:
        Node(string val1,Node* forward1, Node* back1){
            val=val1;
            forward=forward1;
            back=back1;
        }
        Node(string val1){
            val=val1;
            forward=NULL;
            back=NULL;
        }
    };
    Node* current_page;
    BrowserHistory(string homepage) {
        current_page= new Node(homepage);
    }
    
    void visit(string url) {
        Node* new_node= new Node(url);
        current_page->forward=new_node;
        new_node->back=current_page;
        current_page=new_node;
    }
    
    string back(int steps) {
        while(steps>0){
            if(current_page->back!=NULL){
                current_page=current_page->back;
            }
            else{
                break;
            }
            steps--;
        }
        return current_page->val;
    }
    
    string forward(int steps) {
        while(steps>0){
            if(current_page->forward!=NULL){
                current_page=current_page->forward;
            }
            else{
                break;
            }
            steps--;
        }
        return current_page->val;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */