class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> res(arr.size());
        // set<int> s(arr.begin(), arr.end());
        vector<int> v(arr);
        sort(v.begin(), v.end());
        unordered_map<int, int> m;
        int k = 1;
        for(auto it: v){
            if(m[it] == 0){
                m[it] = k;
                k++;
            }
        }
        for(int i = 0;i<arr.size();i++){
            res[i] = m[arr[i]];
        }
        return res;
    }
};