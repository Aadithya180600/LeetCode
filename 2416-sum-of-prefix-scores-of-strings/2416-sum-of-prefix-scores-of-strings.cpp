class TrieNode{
public:
    TrieNode* node[26];
    int c;

    TrieNode(){
        for(int i = 0;i<26;i++){
            node[i] = nullptr;
        }
        c = 0;
    }

    TrieNode(int val){
        for(int i = 0;i<26;i++){
            node[i] = nullptr;
        }
        c = val;
    }
};
class Solution {
public:
    TrieNode* root = new TrieNode();

    void insert(string s){
        TrieNode* curr = root;
        int i = 0;
        
        while(i<s.length() && curr->node[s[i]-'a'] != nullptr){
            curr = curr->node[s[i]-'a'];
            curr->c++;
            i++;
        }
        while(i<s.length()){
            curr->node[s[i]-'a'] = new TrieNode(1);
            curr = curr->node[s[i]-'a'];
            i++;
        }
    }

    int countPrefix(string s){
        int cl = 0;

        TrieNode* curr = root;
        int i = 0;
        
        while(i<s.length() && curr->node[s[i]-'a'] != nullptr){
            curr = curr->node[s[i]-'a'];
            cl += curr->c;
            i++;
        }
        return cl;
    }

    vector<int> sumPrefixScores(vector<string>& words) {
        int n = words.size();
        vector<int> v(n);
        for(string s: words){
            insert(s);
        }

        for(int i = 0;i<n;i++){
            v[i] = countPrefix(words[i]);
        }
        return v;
    }
};