class Node {
public:
    int key;
    int value;
    Node* prev;
    Node* next;

    Node(int key, int value){
        this->key = key;
        this->value = value;

        prev = nullptr;
        next = nullptr;
    }
};

class LRUCache {
private:
    int capacity;
    unordered_map<int, Node*> cache;
    Node* left;
    Node* right;

    void remove(Node* node){
        Node* prevNode = node->prev;
        Node* nextNode = node->next;

        prevNode->next = nextNode;
        nextNode->prev = prevNode;
    }

    void insert(Node* node){
        Node* prevNode = right->prev;
        Node* nextNode = right;

        prevNode->next = node;
        node->prev = prevNode;
        node->next = nextNode;
        nextNode->prev = node;
    }

public:
    LRUCache(int capacity) {
        this->capacity = capacity;
        left = new Node(0, 0);
        right = new Node(0, 0);

        left->next = right;
        right->prev = left;
    }
    
    int get(int key) {
        if(cache.find(key) == cache.end()){
            return -1;
        }

        Node* node = cache[key];

        remove(node);
        insert(node);

        return node->value;
    }
    
    void put(int key, int value) {
        if(cache.find(key) != cache.end()){
            Node* node = cache[key];
            node->value = value;

            remove(node);
            insert(node);
            return;
        }

        Node* newNode = new Node(key, value);
        cache[key] = newNode;
        insert(newNode);

        if(cache.size() > capacity){
            Node* lru = left->next;
            remove(lru);

            cache.erase(lru->key);
            delete(lru);
        }
    }
};
