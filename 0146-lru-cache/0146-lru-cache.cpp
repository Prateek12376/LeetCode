struct Node{
    int key;
    int data;
    Node* next;
    Node* prev;
    Node(int key1,int data1, Node* next1, Node* prev1){
        key=key1;
        data=data1;
        next=next1;
        prev=prev1;
    }
    Node(int key1,int data1){
        key=key1;
        data=data1;
    }
};
class LRUCache {
    map<int,Node*>map1;
    int limit;
    Node* head;
    Node* tail;
public:
    LRUCache(int capacity) {
        limit=capacity;
        map1.clear();
        head= new Node(-1,-1);
        tail= new Node(-1,-1);
        head->next=tail;
        tail->prev=head;
    }
    void insert_after_head(Node* temp){
        Node* node_after_head = head->next;
        head->next=temp;
        temp->prev=head;
        temp->next=node_after_head;
        node_after_head->prev=temp;
    }
    void delete_node(Node* temp){
        Node* after_node= temp->next;
        Node* prev_node= temp->prev;
        prev_node->next=after_node;
        after_node->prev=prev_node;
    }
    
    int get(int key) {  
        if(map1.find(key)==map1.end()){
            return -1;
        }
        Node* new_node = map1[key];
        delete_node(new_node);
        insert_after_head(new_node);
        return new_node->data;
    }
    
    void put(int key, int value) {
        if(map1.find(key)!=map1.end()){
            Node* put_node= map1[key];
            put_node->data=value;
            delete_node(put_node);
            insert_after_head(put_node);
        }
        else{
            if(map1.size()==limit){
                Node* del_node= tail->prev;
                map1.erase(del_node->key);
                delete_node(del_node);
                delete del_node;
            }
            Node* new_node= new Node(key,value);
            insert_after_head(new_node);
            map1[key]=new_node;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */