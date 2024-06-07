// class Solution {
// public:
//     string replaceWords(vector<string>& dictionary, string sentence) {
//         sort(dictionary.begin(), dictionary.end());
//         int v[26];
//         for(int i=0;i<26;i++){
//             v[i] = 0;
//         }
        
//         for(string word: dictionary){
//             for(char c: word){
//                 if(v[c-'a'] == nullptr)
//                 // if(vv == nullptr)
//             }
//             break;
//         }
//         return "";
//     }
// };

// cat, catt, bat rat, battr bater

// 0.   0.   1    1
// c -> a -> t -> t

// 0.   0.   1.   0.   1
// b -> a -> x -> t -> r
//      |    |
//      v    v
//     1t 0 e -> r 1

// 0.   0.   1
// r -> a -> t

// ([,,([([,,,,,([,,,,,([], 1),,,,], 0),,,],0),,,,],0)],0)

// class Trie{
//     char ch;
//     Trie trie[26];
//     bool flag = false;

//     Trie(char c, bool isend){
//         ch = c;
//         flag = isend;
//     }

//     Trie insert(char c, bool isend){
//         if(a[c='a'] != null) return a[c-'a'];
//         Trie n = new Trie(c, isend);
//         a[c-'a'] = n;
//         return n;
//     }

//     int search(string word){
//         Trie t = this;
//         int i;
//         for(i = 0; i<word.size();i++){
//             Trie k = t.trie[word[i]-'a'];
//             if(k != null){
//                 if(k.flag) return i;
//                 else{
//                     t = k;
//                 }
//             }
//             else{
//                 return -1;
//             }
//         }
//         return -1;
//     }


// }


// Trie start = new Trie('', 0);
// start.insert(c);

// Trie c = new Trie('c', false);
// r = c.insert('a',0);


// val = start.search(cattle);

// if(val == -1) word = word;
// else{
//     word = word[:val+1]
// }


class TrieNode {
public:
    bool isEnd;
    vector<TrieNode*> children;

    TrieNode() : children(26, nullptr) { isEnd = false; }
};

class Trie {
private:
    TrieNode* root;

public:
    Trie() { root = new TrieNode(); }

    void insert(string word) {
        TrieNode* current = root;
        for (char c : word) {
            if (current->children[c - 'a'] == nullptr) {
                current->children[c - 'a'] = new TrieNode();
            }
            current = current->children[c - 'a'];
        }
        current->isEnd = true;
    }

    // Find the shortest root of the word in the trie
    string shortestRoot(string word) {
        TrieNode* current = root;
        for (int i = 0; i < word.length(); ++i) {
            char c = word[i];
            if (current->children[c - 'a'] == nullptr) {
                // There is not a corresponding root in the trie
                return word;
            }
            current = current->children[c - 'a'];
            if (current->isEnd) {
                return word.substr(0, i + 1);
            }
        }
        // There is not a corresponding root in the trie
        return word;
    }
};

class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        istringstream sStream(sentence);

        Trie dictTrie;
        for (string word : dictionary) {
            dictTrie.insert(word);
        }

        // Replace each word in sentence with the corresponding shortest root
        string word;
        string newSentence;
        while (getline(sStream, word, ' ')) {
            newSentence += dictTrie.shortestRoot(word) + " ";
        }

        newSentence.pop_back();  // remove extra space
        return newSentence;
    }
};