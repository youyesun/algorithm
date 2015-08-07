class TrieNode{

public:

    bool isword;

    TrieNode *next[26];

    TrieNode(bool b=false){

        isword = b;

        memset(next,0,sizeof(next));

    }

};



class WordDictionary {

public:

    WordDictionary(){

        root = new TrieNode();

    }



    // Adds a word into the data structure.

    void addWord(string word) {

        TrieNode *p = root;

        for(int i = 0; i < word.length(); i++){

            if(p->next[word[i]-'a'] == NULL)

                p->next[word[i]-'a'] = new TrieNode();

            p = p->next[word[i]-'a'];

        }

        p->isword = true;

    }



    // Returns if the word is in the data structure. A word could

    // contain the dot character '.' to represent any one letter.

    bool search(string word) {

        return searchHelper(word,root);

    }

    

private:

    TrieNode *root;

    bool searchHelper(string word, TrieNode* root){

        TrieNode* p = root;

        for(int i = 0; i < word.length() && p!=NULL; i++){

            if(word[i] != '.')

                p=p->next[word[i] - 'a'];

            else{

                TrieNode *tmp = p;

                for(int j = 0; j < 26; j++){

                    p = tmp->next[j];

                    if(searchHelper(word.substr(i+1),p))

                        return true;

                }

            }

        }

        return p && p->isword;

    }

};



// Your WordDictionary object will be instantiated and called as such:

// WordDictionary wordDictionary;

// wordDictionary.addWord("word");

// wordDictionary.search("pattern");
