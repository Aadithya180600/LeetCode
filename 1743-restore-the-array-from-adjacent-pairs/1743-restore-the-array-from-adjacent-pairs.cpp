class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& p) {
        unordered_map<int, vector<int>> m;
        unordered_map<int, bool> s;
        for(auto i:p){
            m[i[0]].push_back(i[1]);
            m[i[1]].push_back(i[0]);
            s[i[0]] = false;
            s[i[1]] = false;
        }
        stack<int> ss;
        for(auto i:m){
            if(i.second.size() == 1) {
                ss.push(i.first);
                break;
            }
        }
        vector<int> v;
        while(!ss.empty()){
            int t = ss.top();
            ss.pop();
            v.push_back(t);
            s[t] = true;
            for(auto i:m[t]){
                if(!s[i]) ss.push(i);
            }
        }
        return v;
    }
};