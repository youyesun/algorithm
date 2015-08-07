class TrieNode {

public:

    bool isword;

    TrieNode *next[26];

    // Initialize your data structure here.

    TrieNode(bool b=false) {

        isword = b;

        memset(next,0,sizeof(next));

    }

};



class Trie {

public:

    Trie() {

        root = new TrieNode();

    }



    // Inserts a word into the trie.

    void insert(string word) {

        int wl = word.length();

        TrieNode* p = root;

        for(int i = 0; i < wl; i ++){

            if(p->next[word[i] - 'a'] == NULL)

                p->next[word[i] - 'a'] = new TrieNode();

            p = p->next[word[i] - 'a'];

        }

        p->isword = true;

    }



    // Returns if the word is in the trie.

    bool search(string word) {

        TrieNode *p = find(word);

        return p!=NULL && p->isword;

    }



    // Returns if there is any word in the trie

    // that starts with the given prefix.

    bool startsWith(string prefix) {

        return find(prefix) != NULL;

    }



private:

    TrieNode* root;

    TrieNode* find(string word){

        TrieNode* p = root;

        for(int i = 0; i < word.length()&&p!=NULL; i++){

            p = p->next[word[i] - 'a'];

        }

        return p;

    }

};



// Your Trie object will be instantiated and called as such:

// Trie trie;

// trie.insert("somestring");

// trie.search("key");
