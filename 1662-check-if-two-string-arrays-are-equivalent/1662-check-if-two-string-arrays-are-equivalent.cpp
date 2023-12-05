class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        
        string s = "", t = "";
        for(string i:word1){
            s+=i;
        }
        for(string j:word2){
            t+=j;
        }
        return s == t;
        // int i = 0, j = 0;
        // int n = 0, m = 0;
        // while(i<word1.size() & j<word2.size()){
        //     if(word1[i][n++] != word2[j][m++]){
        //         return false;
        //     }
        //     if(n == word1[i].size()) {
        //         i++;
        //         n = 0;
        //     }
            
        //     if(m == word2[j].size()){
        //         j++;
        //         m = 0;
        //     }
        // }
        // if(i<word1.size() or j<word2.size()) {
        //     return false;
        // }
        // return true;
    }
};