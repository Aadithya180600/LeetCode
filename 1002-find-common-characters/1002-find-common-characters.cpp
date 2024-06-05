class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<int> r(26, 10001);
        for(string word: words){
            vector<int> a(26, 0);
            for(char c:word){
                a[c-'a']++;
            }
            for(int i = 0;i<26;i++){
                r[i] = min(a[i], r[i]);
            }
        }
        vector<string> res;
        for(int i = 0;i<26;i++){
            char c = 'a'+i;
            // if(r[i]==10001) continue;
            for(int j = 0;j<r[i];j++) {
                string s;
                s.push_back(c);
                res.push_back(s);
            }
        }
        return res;
    }
};