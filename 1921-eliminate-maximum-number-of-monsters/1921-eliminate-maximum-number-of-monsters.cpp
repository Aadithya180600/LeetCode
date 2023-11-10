class Solution {
public:
    int eliminateMaximum(vector<int>& v, vector<int>& s) {
        int n = v.size();
        vector<float> d;
        for(int i = 0;i<n;i++) {
            d.push_back(v[i]/(float)s[i]);
        }
        sort(d.begin(), d.end());
        for(int i = 0;i<n;i++){
            if(i>=d[i]) {
                return i;
            }
        }
        return n;
    }
};