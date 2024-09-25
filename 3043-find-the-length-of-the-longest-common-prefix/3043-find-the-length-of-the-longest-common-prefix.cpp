class TrieNode{
public:
    TrieNode* node[10];

    TrieNode(){
        for(int i = 0;i<10;i++){
            node[i] = nullptr;
        }
    }
};

class Solution {
public:
    TrieNode* root;
    void insert(string val){
        TrieNode* temp = root;
        int i = 0;
        while(i< val.length() && temp->node[val[i]-'0'] != nullptr) {
            temp = temp->node[val[i]-'0'];
            i++;
        }
        while(i<val.length()){
            temp->node[val[i]-'0'] = new TrieNode();
            temp = temp->node[val[i]-'0'];
            i++;
        }
    }

    int searchPrefix(string val){
        TrieNode* temp = root;
        int i = 0;
        while(i< val.length() && temp->node[val[i]-'0'] != nullptr) {
            temp = temp->node[val[i]-'0'];
            i++;
        }
        return i;
    }
    
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        int maxCount = 0;
        root = new TrieNode();
        for(int i: arr1){
            insert(to_string(i));
        }
        for(int i: arr2){
            maxCount = max(maxCount, searchPrefix(to_string(i)));
        }
        return maxCount;
    }
};