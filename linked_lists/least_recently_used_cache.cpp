/*
    Problem Statement: LRU Cache
        Design and implement a data structure for Least Recently Used (LRU) cache.
        It should support the following operations:

        get(key) – Return the value of the key if the key exists in the cache, otherwise return -1.

        put(key, value) – Update or insert the value. If the number of keys exceeds the cache capacity, evict the least recently used key.

        Implement the cache such that both operations run in O(1) time.
*/

#include <iostream>
#include <unordered_map>

using namespace std;

struct ListNode{
    int key;
    int val;
    ListNode *next = NULL;
    ListNode *prev = NULL;

    ListNode(int key, int val): key(key), val(val) {};
};

class LRU_Cache{
    private:
        int capacity;
        unordered_map<int, ListNode*> hashmap;
        ListNode *head;
        ListNode *tail;

        void move_to_front(ListNode *node){
            if(node == head){
                return;
            }

            else if(node == tail){
                ListNode *node_prev = node->prev;
                node_prev->next = NULL;
                tail = node_prev;
            }

            else{
                ListNode *node_prev = node->prev;
                ListNode *node_next = node->next;

                node_prev->next = node_next;
                node_next->prev = node_prev;  
            }

            node->next = head;
            node->prev = NULL;
                
            head->prev = node;
            head = node;
        }

        void insert_new_node_at_front(int key, int value) {
            ListNode * newNode = new ListNode(key, value);
            newNode->next = head;

            if(head){
                head->prev = newNode;
            }

            head = newNode;

            if(!tail){
                tail = newNode;
            }
            hashmap[key] = newNode;

        }

        void evict_from_end(){
            if(!tail){
                return;
            }

            hashmap.erase(tail->key);

            if(head == tail){
                delete tail;
                head = tail = NULL;
                return;
            }

            else{
                ListNode *tail_prev = tail->prev;
                tail_prev->next = NULL;
        
                delete tail;
                tail = tail_prev;          
            }

        }
    
    public:
        LRU_Cache(int capacity) : capacity(capacity), head(NULL), tail(NULL) {}

        ~LRU_Cache() {
            ListNode* current = head;
            while (current != nullptr) {
                ListNode* nextNode = current->next;
                delete current;
                current = nextNode;
            }
        
            head = nullptr;
            tail = nullptr;
            hashmap.clear(); 
        }

        int get(int key){
            if(hashmap.find(key) == hashmap.end()){
                return -1;
            }

            ListNode *node = hashmap.at(key);
            move_to_front(node);
            return node->val;
        }

        void put(int key, int val){
            if(hashmap.find(key) != hashmap.end()){
                ListNode *node = hashmap.at(key);

                node->val = val;
                move_to_front(node);
            }
            
            else{
                if(hashmap.size() == capacity){
                    evict_from_end();
                }
                insert_new_node_at_front(key, val);
            }
        }
};

int main() {
    cout << "Test Case 1: Basic put and get\n";
    LRU_Cache cache(2);
    cache.put(1, 100);
    cache.put(2, 200);
    cout << "get(1): " << cache.get(1) << " (expected 100)\n"; // 100
    cout << "get(2): " << cache.get(2) << " (expected 200)\n"; // 200

    cout << "\nTest Case 2: Eviction on capacity\n";
    cache.put(3, 300); // evicts key 1
    cout << "get(1): " << cache.get(1) << " (expected -1)\n"; // -1
    cout << "get(3): " << cache.get(3) << " (expected 300)\n"; // 300

    cout << "\nTest Case 3: Update existing key\n";
    cache.put(2, 222);
    cout << "get(2): " << cache.get(2) << " (expected 222)\n"; // 222

    cout << "\nTest Case 4: Access updating recency\n";
    cache.get(3);         // access 3 to mark as most recently used
    cache.put(4, 400);    // evicts key 2
    cout << "get(2): " << cache.get(2) << " (expected -1)\n"; // -1
    cout << "get(3): " << cache.get(3) << " (expected 300)\n"; // 300
    cout << "get(4): " << cache.get(4) << " (expected 400)\n"; // 400

    cout << "\nTest Case 5: get non-existent key\n";
    cout << "get(99): " << cache.get(99) << " (expected -1)\n"; // -1

    cout << "\nTest Case 6: Cache of capacity 1\n";
    LRU_Cache tinyCache(1);
    tinyCache.put(10, 1000);
    cout << "get(10): " << tinyCache.get(10) << " (expected 1000)\n"; // 1000
    tinyCache.put(20, 2000); // evicts 10
    cout << "get(10): " << tinyCache.get(10) << " (expected -1)\n";   // -1
    cout << "get(20): " << tinyCache.get(20) << " (expected 2000)\n"; // 2000

    cout << "\nAll tests completed.\n";
    return 0;
}

