/*
 * @lc app=leetcode.cn id=146 lang=cpp
 *
 * [146] LRU 缓存
 */

// @lc code=start

// class LRUCache {
//     public:
//         struct Node {
//             int key;
//             int val;
//             Node* prev;
//             Node* next;
//             Node(int k, int v) : key(k), val(v), prev(nullptr), next(nullptr) {}
//         };
        
//         void addToHead(Node* node) {
//             node->prev = head;
//             node->next = head->next;
//             head->next->prev = node;
//             head->next = node;
//         }
        
//         void removeNode(Node* node) {
//             node->prev->next = node->next;
//             node->next->prev = node->prev;
//         }
        
//         void moveToHead(Node* node) {
//             removeNode(node);
//             addToHead(node);
//         }
        
//         Node* removeTail() {
//             Node* node = tail->prev;
//             removeNode(node);
//             return node;
//         }
    
//         unordered_map<int, Node*> cache;
//         Node* head;
//         Node* tail;
//         int capacity;
        
//         LRUCache(int capacity) : capacity(capacity) {
//             head = new Node(-1, -1);
//             tail = new Node(-1, -1);
//             head->next = tail;
//             tail->prev = head;
//         }
        
//         int get(int key) {
//             if (cache.find(key) == cache.end()) return -1;
//             Node* node = cache[key];
//             moveToHead(node);
//             return node->val;
//         }
        
//         void put(int key, int value) {
//             if (cache.find(key) != cache.end()) {
//                 Node* node = cache[key];
//                 node->val = value;
//                 moveToHead(node);
//             } else {
//                 Node* node = new Node(key, value);
//                 cache[key] = node;
//                 addToHead(node);
//                 if (cache.size() > capacity) {
//                     Node* removed = removeTail();
//                     cache.erase(removed->key);
//                     delete removed;
//                 }
//             }
//         }
//     };
class LRUCache {
    public:
        struct Node {
            int key;
            int val;
            Node * prev;
            Node * next;
            Node():key(),val(),prev(nullptr),next(nullptr){}
            Node(int k, int v):key(k),val(v),prev(nullptr),next(nullptr){}
        };
        
        unordered_map<int, Node*> HashTable;
        Node * head ;
        Node * tail ;
        int capacity;
        LRUCache(int capacity) {
            this->capacity = capacity;
            head = new Node();
            tail = new Node();
            head -> next = tail;
            tail -> prev = head;
        }
        
        int get(int key) {
           if(HashTable.count(key) == 0) return -1;
           Node * node = HashTable[key];
           moveToHead(node);
           return node->val;
        }
        
        void put(int key, int value) {
            if(HashTable.count(key) != 0)
            {
                Node * node = HashTable[key];
                node->val = value;
                moveToHead(node);
            }
            else{
                Node * new_node = new Node(key,value);
                HashTable[key] = new_node;
                addNode(new_node);
                if(HashTable.size() > capacity)
                {
                    Node * tail_node = tail->prev;
                    eraseNode(tail_node);
                    HashTable.erase(tail_node->key);
                    delete tail_node;
                }
            }
        }
        void eraseNode(Node* node)
        {
            Node * tmp = node->next;
            if(tmp) tmp->prev = node->prev;
            Node * prev = node->prev;
            if(prev) prev->next = tmp;
        }
    
        void addNode(Node*& node)
        {
            Node * tmp = head->next;
            head->next = node;
            node->next = tmp;
            tmp->prev = node;
            node->prev = head;
        }
        
        void moveToHead(Node*& node)
        {
            eraseNode(node);
            addNode(node);
        }
    };
/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end

