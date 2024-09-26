class TrieNode{
public:
    TrieNode* node[26];
    bool isEnd;

    TrieNode(){
        for(int i = 0;i<26;i++){
            node[i] = nullptr;
        }
        isEnd = false;
    }

};
class Solution {
public:
    TrieNode* root = new TrieNode();

    string res = "";

    void insert(string s){
        TrieNode* curr = root;
        
        for(int i = 0;i<s.length();i++){
            if(curr->node[s[i]-'a'] == nullptr){
                curr->node[s[i]-'a'] = new TrieNode();
            }
            curr = curr->node[s[i]-'a'];

        }
        curr->isEnd = true;
        
    }

    void searchprefix(string s){
        TrieNode* curr = root;
        int n = s.length();
        bool flag = true;
        for(int i = 0;i<n;i++){
            curr = curr->node[s[i]-'a'];
            if(curr == nullptr) { break; }
            if(!curr->isEnd) {
                flag = false;
            }
        }
        if(flag){
            if(res.length() < n or (res.length() == n and res > s)){
                res = s;
            }
        }
    }

    string longestWord(vector<string>& words) {
        for(string s: words){
            insert(s);
        }
        for(string s: words){
            searchprefix(s);
        }
        return res;
    }
};