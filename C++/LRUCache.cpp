class LRUNode{
public:
    int key;
    int value;
    LRUNode* next;
    LRUNode* prev;
    
    LRUNode(int k, int v) {
        key = k;
        value = v;
        next = NULL;
        prev = NULL;
    }
};

class LRUCache{
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
        head = new LRUNode(0, 0);
        tail = new LRUNode(0, 0);
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        int value;
        
        if(mp.find(key) == mp.end()) {
            value = -1;
            
        } else {
            LRUNode* node = mp[key];
            access(node);
            value = node->value;
        }
        
        return value;
    }
    
    void set(int key, int value) {
        int val = get(key);
        if(val != -1) {
            mp[key]->value = value;
            return;
        }
        
        if(mp.size() >= capacity) {
            LRUNode* rmNode = tail->prev;
            
            tail->prev = rmNode->prev;
            rmNode->prev->next = tail;
            
            mp.erase(rmNode->key);
            delete rmNode;
        }
        
        LRUNode* newNode = new LRUNode(key, value);
        
        newNode->next = head->next;
        head->next = newNode;
        newNode->prev = head;
        newNode->next->prev = newNode;
        
        mp[key] = newNode;
    }
    
private:
    int capacity;
    unordered_map<int, LRUNode*> mp;
    LRUNode* head;
    LRUNode* tail;
    
    void access(LRUNode* node) {
        node->next->prev = node->prev;
        node->prev->next = node->next;
        
        node->next = head->next;
        head->next = node;
        node->prev = head;
        node->next->prev = node;
    }
};