class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string, vector<string>> vv;
        vector<vector<string>> ans;
        for(string s : strs){
            string t = s;
            // vector<int> v(26);
            // for(char c:s){
            //     v[c-'a']++;
            // }
            sort(s.begin(), s.end());
            vv[s].push_back(t);
        }
        for(auto it:vv){
            ans.push_back(it.second);
        }
        return ans;
    }
};