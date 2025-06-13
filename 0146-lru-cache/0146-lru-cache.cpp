class LRUCache {
public:

    class Node {
        public:
            int key,val;
            Node *prev, *next;

            Node(int key,int val) {
                this->key = key, this->val = val;
                prev = next = nullptr ;
            }
    };

    Node* head = new Node(-1,-1); //Dummy Nodes
    Node* tail = new Node(-1,-1);

    unordered_map<int, Node*> umap;
    int limit;

    void addNode(Node* newNode) {
        Node* oldNext = head->next;

        newNode->next = oldNext;
        newNode->prev = head;

        head->next= newNode;
        oldNext->prev = newNode;
    }

    void deleteNode(Node *delNode){
        Node* oldPrev = delNode->prev;
        Node* oldNext = delNode->next;

        oldPrev->next = oldNext ;
        oldNext->prev = oldPrev ;
        //delete(oldNode);
    }

    LRUCache(int capacity) {
        limit = capacity;
        head->next = tail;
        tail->next = head;
    }
    
    int get(int key) {
        if(umap.find(key) == umap.end()) {
            return -1;
        }

        Node* ansNode = umap[key];
        umap.erase(key);
        deleteNode(ansNode);
        addNode(ansNode);

        umap[key] = head->next ;

        return ansNode->val ;
    }
    
    void put(int key, int value) {
        if(umap.find(key) != umap.end()) {
            Node * node = umap[key];
            umap.erase(key);
            deleteNode(node);
        }
        if(umap.size() == limit) {
            umap.erase(tail->prev->key);
            deleteNode(tail->prev);
        }

        Node* newNode = new Node(key,value);
        addNode(newNode);
        umap[key] = head->next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */