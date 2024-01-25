class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<vector<int>, vector<string>> vv;
        vector<vector<string>> ans;
        for(string s : strs){
            vector<int> v(26);
            for(char c:s){
                v[c-'a']++;
            }
            vv[v].push_back(s);
        }
        for(auto it:vv){
            ans.push_back(it.second);
        }
        return ans;
    }
};