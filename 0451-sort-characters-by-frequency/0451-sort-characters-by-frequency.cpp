class Solution {
public:
    string frequencySort(string s) {
        map<char, int> m;
        for(char c: s){
            m[c]++;
        }
        vector<pair<int, char>> p;
        for(auto it: m){
            p.push_back(make_pair(it.second, it.first));
        }
        sort(p.begin(), p.end(), greater<pair<int, char>>());
        string ans;
        for(auto it:p)
        {
            for(int i=0;i<it.first;i++)
                ans.push_back(it.second);
        }
        return ans;
    }
};