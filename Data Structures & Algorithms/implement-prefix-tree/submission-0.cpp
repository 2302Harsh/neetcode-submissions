
class trieNode{
public: 
    unordered_map <char, trieNode*> children;
    bool endOfWord = false;
};

class PrefixTree {
    trieNode* root;
public:
    PrefixTree() {
        root = new trieNode();
    }
    
    void insert(string word) {
        trieNode* cur = root;
        for(char c : word){
            if(cur->children.find(c)==cur->children.end()){
                cur->children[c] = new trieNode();
            }
            cur = cur->children[c];
        }
        cur->endOfWord = true;
    }
    
    bool search(string word) {
        trieNode* cur = root;
        for(char c : word){
            if(cur->children.find(c)==cur->children.end()){
                return false;
            }
            cur = cur->children[c];
        }
        return cur->endOfWord;
    }
    
    bool startsWith(string prefix) {
        trieNode* cur = root;
        for(char c: prefix){
            if(cur->children.find(c) == cur->children.end()){
                return false;
            }
            cur = cur->children[c];
        }

        return true;
        
    }
};
