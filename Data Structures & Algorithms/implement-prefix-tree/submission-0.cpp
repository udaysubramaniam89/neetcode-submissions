class TrieNode {
public:
    vector<TrieNode*> children;
    bool isWord;

    TrieNode(){
        children = vector<TrieNode*>(26, nullptr);
        isWord = false;
    }
};

class PrefixTree {
public:
    TrieNode* root;

    PrefixTree(){
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* curr = root;

        for(char ch : word){
            int index = ch - 'a';

            if(curr->children[index] == nullptr){
                curr->children[index] = new TrieNode();
            }
            curr = curr->children[index];
        }
        curr->isWord = true;
    }
    
    bool search(string word) {
        TrieNode* curr = root;

        for(char ch : word){
            int index = ch - 'a';

            if(curr->children[index] == nullptr){
                return false;
            }

            curr = curr->children[index];
        }
        return curr->isWord;
    }
    
    bool startsWith(string prefix) {
        TrieNode* curr = root;

        for(char ch : prefix){
            int index = ch - 'a';

            if(curr->children[index] == nullptr){
                return false;
            }
            curr = curr->children[index];
        }
        return true;
    }
};
