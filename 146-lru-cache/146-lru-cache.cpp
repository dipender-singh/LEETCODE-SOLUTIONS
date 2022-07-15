class LRUCache {
public:
    class ListNode{
        public:
        int key;
        int val;
        ListNode* next;
        ListNode* prev;
        
        ListNode(int key,int val){
            this->val=val;
            this->key=key;
        }
    };
    //We will create a dummy head and a dummy tail
    ListNode* dhead = new ListNode(-1,-1); // Key and value both have value -1
    ListNode* dtail = new ListNode(-1,-1); // Key and value both have value -1
    
    int capa;
    map<int,ListNode*> mp;
    
    LRUCache(int capacity) {
        capa = capacity;
        dhead->next=dtail;
        dtail->prev=dhead;
    }
    
    void addNode(ListNode* temp){
        ListNode* grace = dhead->next;
        temp->prev = dhead;
        temp->next = grace;
        grace->prev = temp;
        dhead->next = temp;
    }
    
    void deleteNode(ListNode* temp){
        ListNode* gracep = temp->prev;
        ListNode* gracen = temp->next;
        gracep->next = gracen;
        gracen->prev = gracep;
    }
    
    int get(int key) {
        if(mp.find(key)!=mp.end()){
//Then in the map we will have a value and corresponding that value we will have the address of the node
            ListNode* temp = mp[key];
            int res = temp->val;
            mp.erase(key);//We will delete the entry becasue now that node is just accesed and that will become 
                          //the last used element but it will not be the least Frequently Used
            deleteNode(temp);//Will delete that element as it has been acessed so we will have to chng its add
            addNode(temp);//Will add it now to the next of the Dummy Head
            mp[key] = dhead->next;
            return res;
        }
        return -1;
    }
    
    void put(int key, int value) {
        //First we will check that this key is already present in the map with another value or not
        if(mp.find(key)!=mp.end()){
            ListNode* already = mp[key];
            mp.erase(key);
            deleteNode(already);
        }
        if(mp.size()==capa){//If that element is not there already and the size of the map is full
                            //we will be deleting the Least Recently Used element that will be at the prev of 
                            //the dummy tail
            mp.erase(dtail->prev->key);
            deleteNode(dtail->prev);
        }
        if(mp.size()<capa){//It means we have to simply add the element on the next position of dummy head
            ListNode *adding_new = new ListNode(key,value);
            addNode(adding_new);
            mp[key]=adding_new;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */