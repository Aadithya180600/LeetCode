class Solution {
public:
    vector<string> generatePossibleNextMoves(string s) {
        string k = s;
        vector<string> v;
        for(int i = 0;i<s.length()-1;i++){
            if(s[i] == '+' and s[i+1] == '+'){
                k[i] = '-';
                k[i+1] = '-';
                v.push_back(k);
                k = s;
            }
        }
        return v;
    }
};