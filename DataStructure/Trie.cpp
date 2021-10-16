//又称前缀树 字典树
#include <stdio.h>
#include <vector>
#include <string>

class Trie {
private:
    vector<Trie*> children;
    bool isEnd;

    Trie* searchPrefix(string prefix){
        Trie* node = this;
        for(auto &ch:prefix){
            if(node->children[ch-'a']==nullptr){
                return nullptr;
            }
            node = node->children[ch-'a'];
        }
        return node;
    }

public:
    Trie():children(26),isEnd(false) {}
    
    void insert(string word) {
        Trie* node = this;
        for(auto &ch:word){
            if(node->children[ch-'a']==nullptr){
                node->children[ch-'a'] = new Trie();
            }
            node = node->children[ch-'a'];
        }
        node->isEnd = true;

    }
    
    bool search(string word) { 
        Trie* node = searchPrefix(word);
        return node!=nullptr && node->isEnd;

    }
    
    bool startsWith(string prefix) {
        Trie* node = searchPrefix(prefix);
        return node!=nullptr;

    }
};
