class Trie {
    struct Node{
        Node* links[26];
        bool flag = false;
        bool containsKey(char ch){
            return links[ch-'a']!=NULL;
        }
        void put(char ch,Node* node){
            links[ch-'a'] = node;
        }
        Node* get(char ch){
            return links[ch-'a'];
        }
        void setEnd(){
            flag = true;
        }
        bool getFlag(Node* node){
            return flag;
        }
    };
    private:
    Node *root;
public:
    Trie() {
        root = new Node();
    }
    
    void insert(string word) {
        Node* node= root;
        for(int i = 0;i<word.size() ;i++){
            if(!node->containsKey(word[i])){
                node->put(word[i],new Node());
            }
            node = node->get(word[i]);
        }
        node->setEnd();
    }
    
    bool search(string word) {
        Node* node = root;
        for(int i = 0;i<word.size() ; i++){
            if(node->containsKey(word[i])){
                node = node->get(word[i]);
            }else{
                return false;
            }
        }
        return node->getFlag(node);
    }
    
    bool startsWith(string prefix) {
        Node* node=  root;
        for(int i = 0;i<prefix.size() ; i++){
            node = node->get(prefix[i]);
            if(node==NULL){
                return false;
            }
            
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */