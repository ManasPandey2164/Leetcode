class LRUCache {
    class ListNode {
    public:
        int key, val;
        ListNode* next;
        ListNode* prev;

        ListNode(int key1, int val1) {
            key = key1;
            val = val1;
            next = nullptr;
            prev = nullptr;
        }
    };
    
private:
    int cap;
    ListNode* head;
    ListNode* tail;
    unordered_map<int,ListNode*> mpp;

public:
    LRUCache(int capacity) {
        cap = capacity;
        head = new ListNode(-1,-1);
        tail = new ListNode(-1,-1);
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        auto it = mpp.find(key);

        if (it == mpp.end()) {
            return -1;
        }

        ListNode* temp = it->second;

        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;

        temp->next = head->next;
        temp->prev = head;
        head->next->prev = temp;
        head->next = temp;

        return temp->val;
    }
    
    void put(int key, int value) {
        if(mpp.find(key) != mpp.end()){
            ListNode* temp = mpp[key];

            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;

            temp->val = value;

            temp->next = head->next;
            temp->prev = head;
            head->next->prev = temp;
            head->next = temp;      
        }
        else{
            ListNode* node = new ListNode(key,value);
            node->next = head->next;
            node->prev = head;
            head->next->prev = node;
            head->next = node;
            mpp[key] = node;
            if(mpp.size()>cap){
                ListNode* temp = tail->prev;
                temp->prev->next = temp->next;
                temp->next->prev = temp->prev;

                mpp.erase(temp->key);
                delete temp;
            }
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */