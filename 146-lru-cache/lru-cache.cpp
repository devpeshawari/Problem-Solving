class dllNode{
public:
    int val;
    dllNode * next;
    dllNode* prev;
    int key;
    dllNode(int num, int id){
        val = num;
        key = id;
    }
};


class LRUCache {
public:
    dllNode * head = new dllNode(-1,-1);
    dllNode * tail = new dllNode(-1,-1);
    int capacity = 0;
    unordered_map<int,dllNode *> mp;
    LRUCache(int _capacity) {
        head->next = tail;
        tail->prev = head;
        capacity = _capacity;
    }
    void insertNode(dllNode * targetNode){
        dllNode * headNext = head->next;
        head->next = targetNode;
        targetNode->prev = head;
        targetNode->next = headNext;
        headNext->prev = targetNode;
    }

    void deleteNode(dllNode * targetNode){
        dllNode * prevNode = targetNode->prev;
        dllNode * nextNode = targetNode->next;
        prevNode->next = nextNode;
        nextNode->prev = prevNode;
    }
    
    int get(int key) {
        if(mp.find(key) == mp.end()) return -1;
        dllNode * targetNode = mp[key];
        int getVal = targetNode->val;
        deleteNode(targetNode);
        insertNode(targetNode);
        return getVal; 

    }
    
    void put(int key, int value) {
        if(mp.find(key) != mp.end()){
            dllNode * node = mp[key];
            node->val = value;
            deleteNode(node);
            insertNode(node);
            return;
        }
        
        if(mp.size() < capacity){
            dllNode * node = new dllNode(value,key);
            mp[key] = node;
            insertNode(node);
        }
        else{
            dllNode * removeNode = tail->prev;
            int removeKey = removeNode->key;
            deleteNode(removeNode);
            mp.erase(removeKey);
            removeNode->key = key;
            removeNode->val = value;
            mp[key] = removeNode;
            insertNode(removeNode);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */