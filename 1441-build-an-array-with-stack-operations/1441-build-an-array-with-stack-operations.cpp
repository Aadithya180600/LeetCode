class Solution {
public:
    vector<string> buildArray(vector<int>& t, int n) {
        vector<string> v;
        int k = 0;
        for(int i = 1; k<(int)t.size() && i<=n; i++){
            if(t[k] == i) {
                v.push_back("Push");
                k++;
            }
            else {
                v.push_back("Push");
                v.push_back("Pop");
            }
        }
        return v;
    }
};