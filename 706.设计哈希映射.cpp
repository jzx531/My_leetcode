/*
 * @lc app=leetcode.cn id=706 lang=cpp
 *
 * [706] 设计哈希映射
 */

// @lc code=start
class MyHashMap {
public:
    int HashTable[1000001];
    int hasValue[1000001];
    MyHashMap() {  
        // memset(HashTable, -1, sizeof(HashTable));
    }
    
    void put(int key, int value) {
        HashTable[key] = value;
        hasValue[key] = 1;
    }
    
    int get(int key) {
        if(hasValue[key] == 0) return -1;
        return HashTable[key];
    }
    
    void remove(int key) {
        hasValue[key] = 0;
        // HashTable[key] = -1;
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */
// @lc code=end

