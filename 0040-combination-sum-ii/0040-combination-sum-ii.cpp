class Solution {
public:
    vector<vector<int>> s;

    void fun(vector<int>& candidates, int ind, int t, vector<int> v, int sum){
        if(sum == t){
            s.push_back(v);
            return;
        }
        int prev = -1;
        for(int i = ind; i < candidates.size();i++){
            if(sum+candidates[i] > t) return;
            if(prev == candidates[i]) continue;
            v.push_back(candidates[i]);
            fun(candidates, i+1, t, v, sum+candidates[i]);
            v.pop_back();
            prev = candidates[i];

        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
       sort(candidates.begin(), candidates.end());
       vector<int> v;
       fun(candidates, 0, target, v, 0);
    //    vector<vector<int>> ans(s.begin(), s.end());
       return s;
    }
};