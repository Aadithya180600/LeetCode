class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        vector<int> v(names.size());
        iota(v.begin(), v.end(), 0);
        stable_sort(v.begin(), v.end(), 
            [&heights](int a, int b) {
                return heights[a]>heights[b];
            });
        vector<string> ans;
        for(int i: v){
            ans.push_back(names[i]);
        }
        return ans;
    }
};