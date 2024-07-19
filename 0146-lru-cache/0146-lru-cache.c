typedef struct LRUNODE {
    size_t key;
    int value;
    struct LRUNODE * next;
    struct LRUNODE * prev;
} LRU_Node;

inline LRU_Node * create_LRU_Node (size_t key , int value )  {
    LRU_Node * node = malloc(sizeof(LRU_Node));
    node->key = key;
    node->value = value;

    return node;
}

typedef struct {
    LRU_Node * oldest;
    LRU_Node * newest;
    LRU_Node ** nodes;
    size_t capacity;
} LRUCache;

/*
void // print_LRUCache ( LRUCache * obj) {
    // printf("{ ");
    size_t capacity = obj->capacity;
    LRU_Node * cur = obj->oldest;
    for (size_t i=0 ; i<capacity-1 ; i++) {
        // printf("%d: %d, ", cur->key, cur->value);
        cur=cur->next;
    }
    // printf("%d: %d }\n", cur->key, cur->value);
}
*/

LRUCache* lRUCacheCreate(size_t capacity) {
    // printf("Creating LRU cache with size %zu.\n",capacity);
    LRUCache * cache = malloc(sizeof(LRUCache));
    LRU_Node ** nodes = calloc(10002,sizeof(LRU_Node *)); // keys are >=0, <=10000; make an extra one for simplicity in creation
    cache->capacity = capacity;
    cache->nodes = nodes;

    // Populate the nodes;
    LRU_Node * curr = create_LRU_Node(10001,0);    // Temporary nodes have key 10001
    cache->oldest = curr;
    curr->prev = NULL;
    for (size_t i=1;i<capacity-1;i++) {
        curr->next = create_LRU_Node(10001,0);
        curr->next->prev = curr;
        curr = curr->next;
    }
    curr->next = create_LRU_Node(10001,0);
    curr = curr->next;
    curr->prev = curr;
    curr->next = NULL;
    cache->newest = curr;

    // printf("LRU Cache created:\n");
    // print_LRUCache(cache);
    // printf("=============\n");
    return cache;
}

int lRUCacheGet(LRUCache* obj, size_t key) {
    // printf("The LRU Cache is\n");
    // print_LRUCache(obj);
    // printf("\nSearching for key %zu to get value...\n",key);
    size_t capacity = obj->capacity;


    LRU_Node * node = obj->nodes[key];
    if (!node) {
        // printf("Key not found.\n");
        return -1;
    }

    // Found the node

    // printf("Key found with value %d.\n",node->value);

    // Update its position
    if (capacity > 1) {
        if (node == obj->oldest) {
            obj->oldest = node->next;
        } else if (!(node ==obj->newest)) {
            node->prev->next = node->next;
        }

        if (!(node ==obj->newest)) {
            node->next->prev = node->prev;  // Remove node from its current position
            node->next = NULL;
            node->prev = obj->newest;   // Put it in the newest position
            obj->newest->next = node;   // Update the newest node
            obj->newest = node;
        }
    }

    // printf("The updated LRU Cache is\n");
    // print_LRUCache(obj);
    // printf("=============\n");
    return node->value;
}

void lRUCachePut(LRUCache* obj, size_t key, int value) {
    // printf("The LRU Cache is\n");
    // print_LRUCache(obj);
    // printf("\nSearching for key %zu to update value to %d...\n",key,value);

    // Search for the key

    size_t capacity = obj->capacity;

    LRU_Node * node = obj->nodes[key];
    if (!node) {
        // printf("Key not found.\n");
        // Did not find the key;

        // Isolate the oldest node
        node = obj->oldest;
        // Remove it from the list;

        (obj->nodes)[node->key] = NULL;
        // Remove it from the linked list
        obj->oldest = node->next;
        free(node);

        // Create the new node
        node = create_LRU_Node (key,value);
        node->prev = obj->newest;
        node->next = NULL;
        // Update the newest
        if (capacity>1) { // newest!=oldest
            obj->newest->next = node;
        } else { // newest=oldest=node
            obj->oldest = node;
        }
        obj->newest = node;
        obj->nodes[key] = node;
        
        // printf("The updated LRU Cache is\n");
        // print_LRUCache(obj);
        // printf("=============\n");
        return;
    };

    // Otherwise, found the node

    // printf("Key found with value %d.\n",node->value);

    // Update its position
    if (capacity > 1) {
        if (node == obj->oldest) {
            obj->oldest = node->next;
        } else if (!(node ==obj->newest)) {
            node->prev->next = node->next;
        }

        if (!(node ==obj->newest)) {
            node->next->prev = node->prev;  // Remove node from its current position
            node->next = NULL;
            node->prev = obj->newest;   // Put it in the newest position
            obj->newest->next = node;   // Update the newest node
            obj->newest = node;
        }
    }

    // Update its value
    node->value = value;

    // printf("The updated LRU Cache is\n");
    // print_LRUCache(obj);
    // printf("=============\n");
}

void lRUCacheFree(LRUCache* obj) {
    LRU_Node * cur = obj->oldest;
    LRU_Node * next;
    while (cur) {
        next = cur->next;
        free(cur);
        cur = next;
    }
    free(obj->nodes);
    free(obj);
}

/**
 * Your LRUCache struct will be instantiated and called as such:
 * LRUCache* obj = lRUCacheCreate(capacity);
 * int param_1 = lRUCacheGet(obj, key);
 
 * lRUCachePut(obj, key, value);
 
 * lRUCacheFree(obj);
*/