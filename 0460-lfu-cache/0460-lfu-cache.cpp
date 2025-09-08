struct Node{
    int key,value,count;
    Node* next;
    Node* prev;
    Node(int key1, int value1 , Node* next1, Node* prev1){
        key=key1;
        value=value1;
        count=1;
        next=next1;
        prev=prev1;
    }
    Node(int key1, int value1){
        key=key1;
        value=value1;
        count=1;
        next=nullptr;
        prev=nullptr;
    }
};
struct List{
    int size;
    Node* head;
    Node* tail;
    List(){
        head= new Node(-1,-1);
        tail = new Node(-1,-1);
        head->next= tail;
        tail->prev=head;
        size=0;
    }
    void add_after_head(Node* temp){
        Node* node= head->next;
        temp->prev=head;
        head->next=temp;
        temp->next=node;
        node->prev=temp;
        size++;
    }
    void delete_node(Node* temp){
        Node* prev_node= temp->prev;
        Node* after_node= temp->next;
        prev_node->next=after_node;
        after_node->prev=prev_node;
        size--;
    }
};
class LFUCache {
    map<int,Node*>key_node;
        map<int,List*>list_map;
        int max_cacheSize;
        int minfreq;
        int currSize;
public:
    LFUCache(int capacity) {
        max_cacheSize=capacity;
        minfreq=0;
        currSize=0;
    }
    void updateFreqListMap(Node* node){
        key_node.erase(node->key);
        list_map[node->count]->delete_node(node);
        if(node->count==minfreq && list_map[node->count]->size==0){
            minfreq++;
        }
        List* nextHigherfreqList = new List();
        if((list_map.find(node->count+1))!=list_map.end()){
            nextHigherfreqList = list_map[node->count+1];
        }
        node->count+=1;
        nextHigherfreqList->add_after_head(node);
        list_map[node->count]=  nextHigherfreqList;
        key_node[node->key]=node;
    }
    
    int get(int key) {
        if(key_node.find(key)!=key_node.end()){
            Node* node= key_node[key];
            int value = node->value;
            updateFreqListMap(node);
            return value;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(max_cacheSize==0){
            return;
        }
        if(key_node.find(key)!=key_node.end()){
            Node* node = key_node[key];
            node->value=value;
            updateFreqListMap(node);
        }
        else{
            if(currSize==max_cacheSize){
                List * list = list_map[minfreq];
                key_node.erase(list->tail->prev->key);
                list_map[minfreq]->delete_node(list->tail->prev);
                currSize--;
                
            }
            currSize++;
            // new avlue has to be added 
            minfreq=1;
            List* listfreq = new List();
            if(list_map.find(minfreq)!=list_map.end()){
                listfreq= list_map[minfreq];
            }
            Node* node= new Node(key,value);
            listfreq->add_after_head(node);
            key_node[key]=node;
            list_map[minfreq]=listfreq;
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */