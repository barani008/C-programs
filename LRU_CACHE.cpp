/*
Design and implement a data structure for Least Recently Used (LRU) cache. It should support the following operations: get and put.

get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
put(key, value) - Set or insert the value if the key is not already present. When the cache reached its capacity, it should invalidate the least recently used item before inserting a new item.

 O(1) time complexity

Example:

LRUCache cache = new LRUCache( 2 (capacity)  );

cache.put(1, 1);
cache.put(2, 2);
cache.get(1);       // returns 1
cache.put(3, 3);    // evicts key 2
cache.get(2);       // returns -1 (not found)
cache.put(4, 4);    // evicts key 1
cache.get(1);       // returns -1 (not found)
cache.get(3);       // returns 3
cache.get(4);       // returns 4
*/
struct Listnode{
    int key;
    int val;
    Listnode* next;
    Listnode* prev;
};
class LRUCache {
public:
    Listnode* head;
    Listnode* tail;
    unordered_map<int, Listnode*> map;
    int cap = 0;
    LRUCache(int capacity) {
        cap = capacity; 
        head = new Listnode();
        tail = new Listnode();
        head->next= tail;
        head->prev= NULL;
        tail->next = NULL;
        tail->prev = head;  
    }
    
    int get(int key) {
        if(map.find(key)!=map.end()){
            Listnode* cur = map[key];
            cur->prev->next = cur->next;
            cur->next->prev = cur->prev;
            Listnode* tmp = head->next;
            head->next = cur;
            tmp->prev = cur;
            cur->next= tmp;
            cur->prev = head;
            return map[key]->val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(cap==0)
            return;
        if(map.find(key)!=map.end()){
            map[key]->val = value;
            Listnode* cur = map[key];            
            cur->prev->next = cur->next;
            cur->next->prev = cur->prev;
            Listnode* tmp = head->next;
            head->next = cur;
            tmp->prev = cur;
            cur->next= tmp;
            cur->prev = head;
        }else{
        Listnode* tmp = new Listnode();
        tmp->val = value;
        tmp->key = key;
        tmp->next = head->next;
        tmp->prev = head;
        head->next->prev = tmp;
        head->next = tmp;
        map[key] = tmp;
        Listnode* cur = head;
            if(map.size()>cap){
                Listnode* last = tail->prev;
                last->prev->next = tail;
                tail->prev = last->prev;
                map.erase(last->key);
                delete(last);  
            }
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */