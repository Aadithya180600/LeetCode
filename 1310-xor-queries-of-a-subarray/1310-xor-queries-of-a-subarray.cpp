class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n = arr.size();
        vector<int> v(n+1);
        for(int i =1;i<=n;i++){
            v[i] = v[i-1] ^ arr[i-1];
        }
        vector<int> ans;
        for(auto it: queries){
            ans.push_back(v[it[1]+1] ^ v[it[0]]);
        }
        return ans;
    }
};