struct Node{
    int key,val;
    Node* next;
    Node* prev;
    Node(int key,int value){
        this->key = key;
        this->val = value;
        next = NULL;
        prev = NULL;
    } 

};


class LRUCache {
    unordered_map<int,Node*>cacheMap;
    Node* head;
    Node* tail;
    int capacity;
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
        head = new Node(-1,-1);
        tail = new Node(-1,-1);
        tail->prev = head;
        head->next = tail;
    }
    
    int get(int key) {
        if(cacheMap.find(key)==cacheMap.end()){
            return -1;
        }
        Node* node = cacheMap[key];
        remove(node);
        add(node);  
        return node->val;
    }
    
    void put(int key, int value) {
        if(cacheMap.find(key)!=cacheMap.end()){
            Node* oldNode = cacheMap[key];
            remove(oldNode);
            delete oldNode;
        }

        Node* newNode = new Node(key,value);
        cacheMap[key] = newNode;
        add(newNode);

        if(cacheMap.size()>capacity){
            Node* nodeToDelete = tail->prev;
            cacheMap.erase(nodeToDelete->key);
            remove(nodeToDelete);
            delete nodeToDelete;
        }
    }
    void add(Node* node){
        Node* nextNode = head->next;
        nextNode->prev =node;
        head->next = node;
        node->prev = head;
        node->next = nextNode;
    }
    void remove(Node* node){
        Node* nextNode= node->next;
        Node* prevNode = node->prev;
        prevNode->next = nextNode;
        nextNode->prev = prevNode;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */